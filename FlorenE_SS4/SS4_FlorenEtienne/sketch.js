
let serial;
let portName = 'COM3';
let options = {baudRate: 9600};

let inData = 0;
let sensors = [0, 0, 0, 0];

let sqSize = 100;
let sqPosX;
let sqPosY = 128;

let cirPosX;
let cirPosY = 128;

let guagePosX = 1080/2;
let guagePosY = 1080/2;
let guageWidth;
let guageHeight = 50;

let colorLength;

function setup() {
  serial = new p5.SerialPort();             
  serial.on('list', printList);             
  serial.on('connected', serverConnected);  
  serial.on('open', portOpen);               
  serial.on('data', serialEvent);            
  serial.on('error', serialError);          
  serial.on('close', portClose);             

  serial.list();                            
  serial.open(portName, options);           
  
  createCanvas(1080 , 720);
  textSize(64);
  textAlign(CENTER);
  rectMode(CENTER);
  noStroke();
}

function draw() {
  background(50);

  sqPosX = map(sensors[0], 0, 2, 0, 100);
  cirPosX = map(sensors[0], 0, 2, 0, 100);
  
  guageWidth = map(sensors[2], 0, 2, 0, 324);

  colorLength = map(sensors[2], 0, 2, 0, 255);

  fill(0, colorLength, 0);

  if (sensors[1] == !0) {
    sqPosY -= 10;
    sqPosY = constrain(sqPosY, 256, 324);
    cirPosY -= 10;
    cirPosY = constrain(cirPosY, 256, 324);
  }

  if (sensors[1] == 0) {
    cirPosY += 10;
    sqPosY += 10;
  }
  
  if (guageWidth <= 0 && sensors[3] == 0) {
    fill(0, colorLength, 0);
    text('TURN THE POT....', width/2, 496);
  }

  if (guageWidth >= 400 && sensors[3] == !0) {
    sqSize += 25;
    sqSize = constrain(sqSize, 100, 200);
    background(255);
    fill(255, 0, 255);
  }

  if (guageWidth >= 400 && sensors[3] == 0) {
    sqSize -= 25;
    sqSize = constrain(sqSize, 100, 200);
    fill(0, 255, 0);
    text('PUSH BUTTON!', width/2, 496);
    circle(cirPosX + (width/2) - 128, cirPosY + height/2, 50);
    circle(cirPosX + (width/2) + 128, cirPosY + height/2, 50);
    cirPosY = constrain(cirPosY, 0, 0);
  }

  rect(sqPosX + (width/2), sqPosY, sqSize);
  sqPosY = constrain(sqPosY, 0, 324);

  rect(guagePosX, guagePosY, guageWidth, guageHeight);
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