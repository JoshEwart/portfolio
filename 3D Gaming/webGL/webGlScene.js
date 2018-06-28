//first, create a canvas to draw onto
var renderScene = new THREE.WebGLRenderer({canvas: document.getElementById('GLcanvas'), antialias: true});
renderScene.setClearColor(0xAA0099);
renderScene.setPixelRatio(window.devicePixelRatio);
renderScene.setSize(window.innerWidth, window.innerHeight);
//scene background set up

//get perspective
var view = new THREE.PerspectiveCamera(50, window.innerWidth / window.innerHeight, 1, 1000);
//setup
var scene = new THREE.Scene();
var lighting = new THREE.AmbientLight(0xffffff, .45);
var secondLight = new THREE.AmbientLight(0xffffff, .5);
scene.add(lighting);
scene.add(secondLight);
var box = new THREE.CubeGeometry(100, 100, 100);
var material = new THREE.MeshLambertMaterial({color: 0x9FFFF9});
var mesh = new THREE.Mesh(box, material);
mesh.position.set(0, 0, -900);
scene.add(mesh);
//RENDER LOOP
requestAnimationFrame(render);
function render() {
    mesh.rotation.x += 0.03;
    mesh.rotation.y += 0.03;
    renderScene.render(scene, view);
    requestAnimationFrame(render);
}
