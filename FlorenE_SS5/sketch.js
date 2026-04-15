let serial;
let portName = 'COM7';
let options = {baudRate: 115200};
let outData = 0; // data value being sent via serial commune

let width = 1080;
let height = 720;

let moveCoverY = 0;

let rectSize = 50;
let spacingX = 30;
let spacingY = 30;
let angle = 0;

function setup() {

  // setting up the serial port in order for p5.js to read the sensors
  
  serial = new p5.SerialPort();             
  serial.on('list', printList);             
  serial.on('connected', serverConnected);  
  serial.on('open', portOpen);               
  serial.on('data', serialEvent);            
  serial.on('error', serialError);          
  serial.on('close', portClose);             

  serial.list();                            
  serial.open(portName, options);

  // setting up p5.js sketch
  createCanvas(width, height);
  rectMode(CENTER);
  noStroke();
}

function draw() {
  background(10);

  angle += 0.009;
  push();
  for (let x = 0; x < width; x += spacingX) {
    for (let y = 0; y < height; y += spacingY) {
      translate(x, y);
      rotate(angle);
      ellipse(0, 0, rectSize, rectSize);
    }
  }
  pop();

  //inside container
  fill(25,25,25);
  rect(width/2, height/2, 512, 256);

  //container cover
  fill(0,0,0);
  rect(width/2, height/2 + moveCoverY, 512, 256);

  if (mouseIsPressed) {
    moveCoverY = constrain(mouseY, 0, 256);
    outData = map(moveCoverY, 0, width, 0, 359); // remap moveCoverY to 0-359 angle range for servo
    outData = floor(outData); // floor() cut off decimal for whole number integers
    print(outData); // debugging sent data in console
  }
  else {
    serial.write(outData + '/n'); //convert to string, and send via 
    // serial with newline character at end of message
  }
}


function printList(portList) {
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serverConnected() {
  print("CONNECTED TO SERVER");
}
 
function portOpen() 
{
  print("SERIAL PORT OPEN");
}
 
function serialEvent() 
{
  let inString = serial.readStringUntil('\n'); // read until newline character
  if (inString.length > 0) //if there's data in the string
  {
    sensors = split(inString, ','); // split the string at commas and store in array
    
    for (let i = 0; i < sensors.length; i++) 
    {
      sensors[i] = Number(sensors[i]);
    }
  } 
}
 
function serialError(err) 
{
  print('ERROR: ' + err);
}
 
function portClose() 
{
  print("*____SERIAL PORT CLOSED");
}
