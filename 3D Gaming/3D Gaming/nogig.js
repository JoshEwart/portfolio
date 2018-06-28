/* TREEFALL.JS 
		OBJECTIVE :  Answer Computer Science Questions correctly by going down the correct hole, if any question is incorrect, you will be sent 
					 back to try again, completing all questions correctly will allow for completion and movement into the next stage!*/





///*** EVENT HANDLERS ***///
document.addEventListener('keydown', playerControl, false);
window.addEventListener("resize", function () { 
    engine.resize();
});

///*** GLOBAL VARIABLES ***///
			var player;
			var ROOMSIZE = 30;
			var canvas = document.getElementById("renderCanvas"); 
			var engine = new BABYLON.Engine(canvas, true); 
			var collide = false;
			var movingNorth = true;
			var index = 1;




///*** SCENE FUNCTION  ***///
            var Scene = function () {

				// Create the scene using the engine
				var scene = new BABYLON.Scene(engine);
				scene.enablePhysics();
				scene.collisionsEnabled = true;
				



///*** IMPORT BLENDER MESHES ***///
		//Portal Mesh
		
				//set up mesh array
				scene.portal = [0];

				//load scene and put meshes into portal array
				BABYLON.SceneLoader.ImportMesh("","","portal.babylon",scene,function(mesh){
					scene.portal[0] = mesh[0];
					scene.portal[1] = mesh[1];
					scene.portal[2] = mesh[2];
					scene.portal[0].translate(BABYLON.Axis.X, -4, BABYLON.Space.WORLD);
					scene.portal[1].translate(BABYLON.Axis.X, -5, BABYLON.Space.WORLD);
				});
				

		//Pipe Maze Mesh
				
				//set up different arrays for the platforms and tubes as there are different collision mechanics involved for both
				scene.plateau = [0];
				scene.tubes = [0];
				
				
				//import the mesh while moving it to a better place in the world and setting up the path fior the character
				BABYLON.SceneLoader.ImportMesh("","","pipeStage.babylon",scene,function(mesh){
					for(i = 0; i < mesh.length; i++){
						mesh[i].translate(BABYLON.Axis.X, -5, BABYLON.Space.WORLD);
						mesh[i].translate(BABYLON.Axis.Y, 5, BABYLON.Space.WORLD);
						
					};
					
					scene.plateau[0] = mesh[12];
					scene.plateau[1] = mesh[13];
					scene.plateau[2] = mesh[14];
					scene.plateau[3] = mesh[15];
					scene.plateau[4] = mesh[16];
					scene.plateau[5] = mesh[17];
					scene.plateau[6] = mesh[18];
					scene.plateau[7] = mesh[19];
					scene.plateau[8] = mesh[20];
					scene.plateau[9] = mesh[21];
					scene.plateau[10] = mesh[22];
					scene.plateau[11] = mesh[23];
					scene.plateau[12] = mesh[24];
					scene.plateau[13] = mesh[25];
					scene.plateau[14] = mesh[26];
					scene.plateau[15] = mesh[27];
					scene.plateau[16] = mesh[28];
					scene.plateau[17] = mesh[36];
					
					scene.tubes[0] = mesh[0];
					scene.tubes[1] = mesh[1];
					


					//scale tubes -- this was done for collision reasons, the full size tubes made it imposible to do the specific collisions done here correctly
					for(i = 0; i < scene.tubes.length; i++){
						scene.tubes[i].scaling = new BABYLON.Vector3(1,0.5,1);
					};					
				});
				

		//Player Mesh
	
				player = BABYLON.MeshBuilder.CreateSphere("player", 1, scene);
				var material = new BABYLON.StandardMaterial("texture", scene);
				material.diffuseTexture = new BABYLON.Texture("Checkerboard_nx.jpg", scene);
				player.material = material;
				player.translate(BABYLON.Axis.Y,.5,BABYLON.Space.WORLD);
				player.checkCollisions = true;


				
				
				
				
				
///*** LIGHTS AND CAMERA ***///
				
				//setup camera to follow player as its child
				var arcCamera = new BABYLON.ArcRotateCamera("Camera", -Math.PI / 2, Math.PI / 2, 3, new BABYLON.Vector3(0,1,-1) , scene);
				arcCamera.parent = player;
				
				 
				// Add lights to the scene
				var light1 = new BABYLON.HemisphericLight("light1", new BABYLON.Vector3(3, 5, 0), scene);
				var light2 = new BABYLON.PointLight("light2", new BABYLON.Vector3(0, 3, -1), scene);
			
				
///** ROOM CREATION ***///

		//Setup Textures 
				var wallColor = new BABYLON.StandardMaterial("wallColor", scene);
				wallColor.diffuseTexture = new BABYLON.Texture("Textures/wall.jpg", scene);

				var groundColor = new BABYLON.StandardMaterial("groundColor", scene);
				groundColor.diffuseTexture = new BABYLON.Texture("Textures/ground.jpg",scene);



		//Physical Ground, Walls, Ceilings, and Barriers

				var ground = BABYLON.Mesh.CreateGround("ground", ROOMSIZE, ROOMSIZE, 1, scene);
				ground.physicsImposter = new BABYLON.PhysicsImpostor(ground, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 0}, scene);
				ground.checkCollisions = true;
				ground.material = groundColor;
			
				
				var northWall = new BABYLON.Plane(0,0,1,-(ROOMSIZE/2));
				northWall.normalize();
				var north = BABYLON.MeshBuilder.CreatePlane("north", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: northWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				north.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				north.checkCollisions = true;
				north.material = wallColor;
				

				var southWall = new BABYLON.Plane(0,0,1,(ROOMSIZE/2));
				southWall.normalize();
				var south = BABYLON.MeshBuilder.CreatePlane("south", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: southWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				south.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				south.checkCollisions = true;
				south.material = wallColor;
				
				
				var eastWall = new BABYLON.Plane(1,0,0,-(ROOMSIZE/2));
				eastWall.normalize();
				var east = BABYLON.MeshBuilder.CreatePlane("east", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: eastWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				east.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				east.checkCollisions = true;
				east.material = wallColor;
				
				
				var westWall = new BABYLON.Plane(1,0,0,(ROOMSIZE/2));
				westWall.normalize();
				var west = BABYLON.MeshBuilder.CreatePlane("west", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: westWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				west.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				west.checkCollisions = true;
				west.material = wallColor;
				
				
				var ceilingWall = new BABYLON.Plane(0,1,0,(ROOMSIZE/2));
				ceilingWall.normalize();
				var ceiling = BABYLON.MeshBuilder.CreatePlane("ceiling", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: ceilingWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				ceiling.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				ceiling.checkCollisions = true;
				ceiling.physicsImposter = new BABYLON.PhysicsImpostor(ceiling, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 0}, scene);
				ceiling.material = groundColor;


				var barrier = new BABYLON.Plane(1,0,0,5);
				barrier.normalize();
				var bar = BABYLON.MeshBuilder.CreatePlane("bar", {height: (ROOMSIZE/4+2), width: ROOMSIZE, sourcePlane: barrier, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				bar.material = wallColor;

				 //data reporter
				var outputplane = BABYLON.Mesh.CreatePlane("outputplane", 10, scene, false);
				outputplane.material = new BABYLON.StandardMaterial("outputplane", scene);
				outputplane.position.x = player.position.x ;
				outputplane.position.y = player.position.y + 1;
				outputplane.position.z = player.position.z + 1;
				outputplane.scaling.y = 0.2;
				outputplane.scaling.x = 0.4;

				var outputplaneTexture = new BABYLON.DynamicTexture("dynamic texture", 512, scene, true);
				outputplane.material.diffuseTexture = outputplaneTexture;
				//outputplane.material.specularColor = new BABYLON.Color4(0, 0, 0, 0.3);
				outputplane.material.emissiveColor = new BABYLON.Color4(1, 1, 1,0.3);
				outputplane.material.backFaceCulling = false;

				outputplaneTexture.drawText("Why can we never get a gig?.", null, 160, "bold 22px verdana", "white");
				outputplaneTexture.drawText("Go left for 1 or right for 0.. ", null, 180, "bold 22px verdana", "white");
				outputplaneTexture.drawText("you have only  16 moves.", null, 200, "bold 22px verdana", "white");
				outputplaneTexture.drawText("guess wrong  and you have to start over ", null, 220, "bold 22px verdana", "white");
				outputplane.parent = player;




///*** COLLISION MECHANICS ***///
				function applyPhysicsOnPortal(item,index){
					if(player.intersectsMesh(item)){
						player.position.y = scene.plateau[12].position.y;
						player.position.x = scene.plateau[12].position.x - 1;
						player.position.z = scene.plateau[12].position.z;
					}
				}
				
				//sets up the collision mechanics for the plateaus, only accounts for collision on the top of the walls, as well as sets a collide statement
				//this collide statement turns on artificial gravity
				
				function applyPhysicsOnPlateaus(item, index){
					item.material = BABYLON.Color3(0,0,0);
					if(player.intersectsMesh(item)){
							player.position.y = item.position.y + 0.6;
							collide = true;
							
					}
					else{
							collide = false;
					}
				}

				
				//sets up the collision mechanics for the tubes, since rigid body mechanics don't exist in babylon, and would cause way too much lag with how many tubes there are, this function was set up to teleport the player character to the corresponding platform when the tube is touched. 
				
				function applyPhysicsOnTubes(item,index){
					if(index == 0){
						item.material = BABYLON.Color3(0,0,0);
					}
					if(index > 0){
						
						outputplaneTexture.drawText("On the right track you are ", null, 240, "bold 22px verdana", "white");
					}
				}
				


				//Funtion used for collisions as a whole, determines collisions with all parts of the imported meshes, as well as the walls. 
				//This function is called in the render loop
				scene.collideUpdate = function(){
					scene.plateau.forEach(applyPhysicsOnPlateaus);
					scene.tubes.forEach(applyPhysicsOnTubes);
					scene.portal.forEach(applyPhysicsOnPortal);

					if(player.intersectsMesh(east)){
						if(movingNorth == true){
							player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
							index = index + 1;
						}
						else{
							player.translate(BABYLON.Axis.Z, 3, BABYLON.Space.LOCAL);
							index = index - 1;
						}
					}else if(player.intersectsMesh(west)){
						if(movingNorth == true){
							player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
							index = index + 1;
						}
						else{
							player.translate(BABYLON.Axis.Z, 3, BABYLON.Space.LOCAL);i
							ndex = index - 1;
						}
					}else if(player.intersectsMesh(south)){
						if(movingNorth == true){
							player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
							index = index + 1;
						}
						else{
							player.translate(BABYLON.Axis.Z, 3, BABYLON.Space.LOCAL);
							index = index - 1;
						}
					}else if(player.intersectsMesh(north)){
						if(movingNorth == true){
							player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
							index = index + 1;
						}
						else{
							player.translate(BABYLON.Axis.Z, 3, BABYLON.Space.LOCAL);
							index = index - 1;
						}
					}
					else if(player.intersectsMesh(bar)){
						if(movingNorth == true){
							player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
							index = index + 1;
						}
						else{
							player.translate(BABYLON.Axis.Z, 3, BABYLON.Space.LOCAL);
							index = index - 1;
						}
					}

					
				}
				
			
				return scene;

			};  //END OF SCENE FUNCTION
                  



///*** EXTERNAL CONTROLS AND CODE IMPLEMENTATIONS ***///
	
		//create the scene

            var scene = Scene(); 
				
				
		//Player movement 		
			
				
			function playerControl(event) {
				keyCode = event.which;
				
				if (keyCode == 87) {
					player.translate(BABYLON.Axis.Z, 0.5, BABYLON.Space.LOCAL);
					movingNorth = true;
				} else if (keyCode == 83) {
					player.translate(BABYLON.Axis.Z, -0.5, BABYLON.Space.LOCAL);
					movingNorth = false;
				} else if (keyCode == 65) {
					player.rotate(BABYLON.Axis.Y, -Math.PI / 6, BABYLON.Space.WORLD);
				} else if (keyCode == 68) {
					player.rotate(BABYLON.Axis.Y, Math.PI / 6, BABYLON.Space.WORLD);
					
				} else if (keyCode == 32){
					player.translate(BABYLON.Axis.Y,2,BABYLON.Space.WORLD);
					player.position.z = 0.095766;
					player.position.x = -8.2;
					player.position.y = 27;
					
				} 
		
			
			}
			
			//Rotates the player character to the correct position in order to be on top of the first platform of the game
			player.rotate(BABYLON.Axis.Y, Math.PI/2, BABYLON.Space.LOCAL);
			player.position.z = 0.095766;
			player.position.x = -8.2;
			player.position.y = 27;
			
			

		//RENDER LOOP / GAME LOOP
			//enacts a fake version of physics by making it so that if the players position is above 1 it will fall 
			//so long as it's not colliding with anything
			var renderLoop = function (){
				scene.collideUpdate();
				scene.render();
				if(player.position.y > 1 && collide == false){
					player.position.y = player.position.y - 0.5;
				}
				
			}	
            engine.runRenderLoop(renderLoop);


