extends Node

@export var player : CharacterBody3D

var serial_manager: GdSerialManager

var tags = [0] # 0xc9 0x1a 0xff 0x0a
var buttons = [0,0,0,0,0]

var tag_1 = 0
var button_up = 0
var button_right = 0
var button_left = 0
var button_down = 0
var button_confirm = 0

func _ready():
	serial_manager = GdSerialManager.new()
	serial_manager.data_received.connect(_on_data_received)
	serial_manager.port_disconnected.connect(_on_port_disconnected)

	# Mode 0: RAW (emit all chunks), 1: LINE_BUFFERED (wait for \n), 2: CUSTOM_DELIMITER
	if serial_manager.open_buffered("COM7", 115200, 1000, 1):
		print("Connected to COM7")

func _process(_delta):
	# This triggers the signals above
	serial_manager.poll_events()
	
	player._spawn_player(tag_1)
	player._move_direction(button_left, button_right, button_up, button_down)
	player._unhandled_input(button_confirm)
	
func _on_data_received(port: String, data: PackedByteArray):
	print("Data from ", port, ": ", data.get_string_from_utf8())
	#serial_manager.read_bytes()
	var inString = data.get_string_from_utf8()
	
	if inString.length() > 0:
		tags = inString.split()
		
		if tags.size() >= 1:
			tag_1 = str_to_var(tags[0])
			
		#------------------------------------------------------
		
		buttons = inString.split(',')
		
		if buttons.size() >= 5:
		
			button_up = str_to_var(buttons[0])
			button_right = str_to_var(buttons[1])
			button_left = str_to_var(buttons[2])
			button_down = str_to_var(buttons[3])
			button_confirm = str_to_var(buttons[4])

func _on_port_disconnected(port: String):
	print("Lost connection to ", port)
