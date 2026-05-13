extends Node

@export var player : PackedScene

var serial_manager: GdSerialManager

#var tag_1 = PackedByteArray([0x0f, 0x3c, 0x2b, 0xaa])

var tags = [0]
var buttons = [0,0,0,0]

var spawn_tag = 0
var button_left = 0
var button_right = 0
var button_up = 0
var button_down = 0

var tags_present = false #for checking if a tag or more are present

func _ready():
	serial_manager = GdSerialManager.new()
	serial_manager.data_received.connect(_on_data_sent)
	serial_manager.port_disconnected.connect(_on_port_disconnected)

	# Mode 0: RAW (emit all chunks), 1: LINE_BUFFERED (wait for \n), 2: CUSTOM_DELIMITER
	if serial_manager.open_buffered("COM7", 9600, 1000, 1):
		print("Connected to COM7")

func _process(_delta):
	serial_manager.poll_events()
	
	#player._spawn_cube(spawn_tag)
	#player._move_direction(button_left, button_right, button_up, button_down)

func _on_data_sent(port: String, data: PackedByteArray):
	print("Data from ", port, ": ", data.get_string_from_utf8())
	
	var inString = data.get_string_from_utf8()
	
	if inString.length() > 0:
		tags = inString.split(',')
		
		if tags.size() >= 1:
			spawn_tag = str_to_var(tags[0])
			
		buttons = inString.split(',')
		
		if buttons.size() >= 4:
			button_left = str_to_var(buttons[0])
			button_right = str_to_var(buttons[1])
			button_up = str_to_var(buttons[2])
			button_down = str_to_var(buttons[3])
		
func _on_port_disconnected(port: String):
	print("Lost connection to ", port)
