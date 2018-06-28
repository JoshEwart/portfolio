document.addEventListener('keydown', playerControl, false);

            var canvas = document.getElementById("renderCanvas"); // Get the canvas element 

            var engine = new BABYLON.Engine(canvas, true); // Generate the BABYLON 3D engine
			var player;
			var ROOMSIZE = 30;
			
		

            /******* StartScreen Function *******/
            var Scene = function () {

				// Create the scene space
				var scene = new BABYLON.Scene(engine);
				scene.enablePhysics(new BABYLON.Vector3(0,-9.81,0), new BABYLON.CannonJSPlugin());
				scene.collisionsEnabled = true;
				
				//let assetsManager = new BABYLON.AssetsManager(scene);
				//assetsManager.addMeshTask("","","","testPipe.babylon");
				//assetsManager.onSuccess = (task) => {
					//console.log("success");
				//}
				//assetsManager.onerror = (task) => {
					//console.log("failure");
				//}
				
				// This is where you create and manipulate meshes
				player = BABYLON.MeshBuilder.CreateSphere("player", 2, scene);
				var material = new BABYLON.StandardMaterial("texture", scene);
				material.diffuseTexture = new BABYLON.Texture("Textures/Checkerboard_px.jpg", scene);
				player.material = material;
				player.translate(BABYLON.Axis.Y,.5,BABYLON.Space.WORLD);
				//player.physicsImpostor = new BABYLON.PhysicsImpostor(player, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 100, restitution: 0.1}, scene);
				player.checkCollisions = true;
				
				// Add a camera to the scene and attach it to the canvas
				
				var arcCamera = new BABYLON.ArcRotateCamera("Camera", -Math.PI / 2, Math.PI / 2, 3, new BABYLON.Vector3(0,1,1) , scene);
				arcCamera.parent = player;
				arcCamera.ellipsoid = new BABYLON.Vector3(1,1,1);
				arcCamera.attachControl(canvas, false, false,1);
				//arcCamera.inputs.
				 
				// Add lights to the scene
				var light1 = new BABYLON.HemisphericLight("light1", new BABYLON.Vector3(3, 5, 0), scene);
				var light2 = new BABYLON.PointLight("light2", new BABYLON.Vector3(0, 3, -1), scene);
			
				
				//Ground and Walls
				var ground = BABYLON.Mesh.CreateGround("ground", ROOMSIZE, ROOMSIZE, 1, scene);
				ground.physicsImposter = new BABYLON.PhysicsImpostor(ground, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 0}, scene);
				ground.checkCollisions = true;

				
				var groundColor = new BABYLON.StandardMaterial("groundColor", scene);
				groundColor.diffuseTexture = new BABYLON.Texture("Textures/ground.jpg",scene);
				ground.material = groundColor;
			
				
				var northWall = new BABYLON.Plane(0,0,1,-(ROOMSIZE/2));
				northWall.normalize();
				var north = BABYLON.MeshBuilder.CreatePlane("north", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: northWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				north.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				north.checkCollisions = true;
				//north.physicsImposter = new BABYLON.PhysicsImpostor(north, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 0}, scene);
				
				
				var wallColor = new BABYLON.StandardMaterial("wallColor", scene);
				wallColor.diffuseTexture = new BABYLON.Texture("Textures/wall.jpg", scene);
				
				north.material = wallColor;
				
				var southWall = new BABYLON.Plane(0,0,1,(ROOMSIZE/2));
				southWall.normalize();
				var south = BABYLON.MeshBuilder.CreatePlane("south", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: southWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				south.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				south.checkCollisions = true;
				//south.physicsImposter = new BABYLON.PhysicsImpostor(south, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 0}, scene);
				
				
				south.material = wallColor;
				
				
				var eastWall = new BABYLON.Plane(1,0,0,-(ROOMSIZE/2));
				eastWall.normalize();
				var east = BABYLON.MeshBuilder.CreatePlane("east", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: eastWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				east.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				east.checkCollisions = true;
				//east.physicsImposter = new BABYLON.PhysicsImpostor(east, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 0}, scene);
				
				east.material = wallColor;
				
				
				var westWall = new BABYLON.Plane(1,0,0,(ROOMSIZE/2));
				westWall.normalize();
				var west = BABYLON.MeshBuilder.CreatePlane("west", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: westWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				west.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				west.checkCollisions = true;
				//west.physicsImposter = new BABYLON.PhysicsImpostor(west, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 0}, scene);
				
				west.material = wallColor;
				
				
				var ceilingWall = new BABYLON.Plane(0,1,0,(ROOMSIZE/2));
				ceilingWall.normalize();
				var ceiling = BABYLON.MeshBuilder.CreatePlane("ceiling", {height: ROOMSIZE, width: ROOMSIZE, sourcePlane: ceilingWall, sideOrientation: BABYLON.Mesh.DOUBLESIDE},scene);
				ceiling.translate(BABYLON.Axis.Y,(ROOMSIZE/2),BABYLON.Space.WORLD);
				ceiling.checkCollisions = true;
				ceiling.physicsImposter = new BABYLON.PhysicsImpostor(ceiling, BABYLON.PhysicsImpostor.BoxImpostor, {mass: 0}, scene);
				ceiling.material = groundColor;
				
				
				var tube;
				var meshTube = BABYLON.SceneLoader.ImportMesh("","","testPipe.babylon",scene, function(mesh){
					let tube = mesh[0];
					tube.position.y = 2;
					tube.position.z = 10;
					tube.checkCollisions = true;
					tube.physicsImposter = new BABYLON.PhysicsImposter(
					tube, BABYLON.PhysicsImposter.BoxImposter, {mass:2},scene);
				});
				
				scene.collideUpdate = function(){
					if(player.intersectsMesh(east)){
						player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
					}else if(player.intersectsMesh(west)){
						player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
					}else if(player.intersectsMesh(south)){
						player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
					}else if(player.intersectsMesh(north)){
						player.translate(BABYLON.Axis.Z, -3, BABYLON.Space.LOCAL);
					}
				}
				
				return scene;

			};
                  



                var scene = Scene(); //Call the createScene function
				
				
				//var tube = BABYLON.SceneLoader.Append("", "testPipe.babylon", scene);
				//tube.physicsImposter = new BABYLON.PhysicsImposter(tube, BABYLON.PhysicsImposter.MeshImposter, {mass: 1});
			
				//tube.translate(BABYLON.Axis.Z, 5, BABYLON.Space.WORLD);
				

					
				
			function playerControl(event) {
				keyCode = event.which;
				console.log(keyCode);
				if (keyCode == 87) {
					player.translate(BABYLON.Axis.Z, 0.5, BABYLON.Space.LOCAL);
				} else if (keyCode == 83) {
					player.translate(BABYLON.Axis.Z, -0.5, BABYLON.Space.LOCAL);
				} else if (keyCode == 65) {
					player.rotate(BABYLON.Axis.Y, -Math.PI / 6, BABYLON.Space.WORLD);
				
				} else if (keyCode == 68) {
					player.rotate(BABYLON.Axis.Y, Math.PI / 6, BABYLON.Space.WORLD);
					
				} else if (keyCode == 32){
					player.translate(BABYLON.Axis.Y,2,BABYLON.Space.WORLD);
					
				} 
				
			
			}
			
			
			
			var renderLoop = function (){
				scene.collideUpdate();
				scene.render();
			}	
            engine.runRenderLoop(renderLoop);


            window.addEventListener("resize", function () { // Watch for browser/canvas resize events
                    engine.resize();
            });
			
