extends CharacterBody3D

# Constant 
const SPEED = 10.5
const JUMP = 10

var gravity = ProjectSettings.get_setting("physics/3d/default_gravity")

# Dialogue
@export var guide_dialogue : Array[String] = []
var dialogue_index = 0 #holding the positions of each string in the array
#var guide_intro = 1
#var guide_intro_end = 5

#var guide_crate_start = 6
var guide_crate = 1
var guide_crate_end = 10

var guide_journal_start = 11
var guide_journal = 1
var guide_journal_end = 12

var guide_docu_start = 13
var guide_docu = 1
var guide_docu_end = 18


# Text
@onready var npc_dialogue: Label3D = $"../NPC/NPCDialogue"
@onready var crate_located: Label3D = $"../CrateItem/CrateLocated"
@onready var journal_located: Label3D = $"../JournalItem/JournalLocated"
@onready var documents_indicator: Label3D = $"../DocumentsItem/DocumentsIndicator"

# Interactable
var npc_interaction = false
var crate_interaction = false
var journal_interaction = false
var docu_interaction = false

var collect_crate = false
var collect_journal = false
var collect_documents = false

# Signals for collecting items
signal collected_item

# Variables for tasks
var task_one_completed = false
var task_two_completed = false
var task_three_completed = false

var item_collected : int = 0

#signal queue_dialogue

#var guide_located = false

func _physics_process(delta: float) -> void:
	
	#camera rotation
	if Input.is_action_pressed("player_left"):
		$CameraController.rotate_y(deg_to_rad(2.5))
	if Input.is_action_pressed("player_right"):
		$CameraController.rotate_y(deg_to_rad(-2.5))
		
	#jump
	if Input.is_action_just_pressed("player_jump") and is_on_floor():
		velocity.y = JUMP
	if not is_on_floor():
		velocity.y -= gravity * delta
		
	#direction of player's movements
	var input_dir = Input.get_vector("player_left","player_right","player_forward","player_backward",)
	var direction = ($CameraController.transform.basis * Vector3(input_dir.x, 0, input_dir.y)).normalized()
	
	if direction:
		velocity.x = direction.x * SPEED
		velocity.z = direction.z * SPEED
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
		velocity.z = move_toward(velocity.z, 0, SPEED)
		
	move_and_slide()
	
	#camera movements
	$CameraController.position = position
	
# NPC Area
func _on_npc_indicator_area_entered(_area: Area3D) -> void:
	npc_interaction = true
	npc_dialogue.text = "Press E"
	
func _on_npc_indicator_area_exited(_area: Area3D) -> void:
	npc_interaction = false 
	npc_dialogue.text = " "

# Crate Area
func _on_crate_indicator_area_entered(_area: Area3D) -> void:
	crate_interaction = true
	crate_located.text = "Press E"
	
func _on_crate_indicator_area_exited(_area: Area3D) -> void:
	crate_interaction = false
	crate_located.text = "V"

# Journal Area
func _on_journal_indicator_area_entered(_area: Area3D) -> void:
	journal_interaction = true
	journal_located.text = "Press E"

func _on_journal_indicator_area_exited(_area: Area3D) -> void:
	journal_interaction = false
	journal_located.text = "V"

# Documents Area
func _on_documents_located_area_entered(_area: Area3D) -> void:
	docu_interaction = true
	documents_indicator.text = "Press E"

func _on_documents_located_area_exited(_area: Area3D) -> void:
	docu_interaction = false
	documents_indicator.text = "V"
	
func _unhandled_input(_InputEvent) -> void:
	if npc_interaction == true and task_one_completed == false and collect_crate == false:
		if Input.is_action_just_pressed("player_interact"):
			npc_dialogue.text = guide_dialogue[dialogue_index]
			dialogue_index += guide_crate
			if dialogue_index == guide_crate_end and dialogue_index < guide_journal_start:
				collect_crate = true
				emit_signal("collected_item")
		#if Input.is_action_just_pressed("player_interact") and task_one_completed == false and collect_crate == true:
			#npc_dialogue.text = "Crate."
			
	if npc_interaction == true and task_two_completed == false and task_one_completed == true and collect_journal == false:
		if Input.is_action_just_pressed("player_interact"):
			#dialogue_index = guide_journal_start
			npc_dialogue.text = guide_dialogue[dialogue_index]
			dialogue_index += guide_journal
			if dialogue_index == guide_journal_end and dialogue_index < guide_docu_start:
				collect_journal = true
				emit_signal("collected_item")
		#if Input.is_action_just_pressed("player_interact") and task_two_completed == false and task_one_completed == true and collect_journal == true:
			#npc_dialogue.text = "Journal."
			
	if npc_interaction == true and task_three_completed == false and task_two_completed == true and task_one_completed == true and collect_documents == false:
		if Input.is_action_just_pressed("player_interact"):
			#dialogue_index = guide_docu_start
			npc_dialogue.text = guide_dialogue[dialogue_index]
			dialogue_index += guide_docu
			if dialogue_index == guide_docu_end:
				collect_documents = true
				emit_signal("collected_item")
		#if Input.is_action_just_pressed("player_interact") and task_three_completed == false and task_two_completed == true and task_one_completed == true and collect_documents == true:
			#npc_dialogue.text = "Documents."
		
	if npc_interaction == true and task_three_completed == true and task_two_completed == true and task_one_completed == true:
		if Input.is_action_just_pressed("player_interact"):
			npc_dialogue.text = "Thank you! These should help you complete your report."

	if crate_interaction == true and collect_crate == true:
		if Input.is_action_just_pressed("player_interact"):
			$"../CrateItem/CrateIndicator".get_parent().queue_free()
			item_collected = 1
			print("Item Collected: " + str(item_collected))
			task_one_completed = true
	if journal_interaction == true and collect_journal == true:
		if Input.is_action_just_pressed("player_interact"):
			$"../JournalItem/JournalIndicator".get_parent().queue_free()
			item_collected = 2
			print("Item Collected: " + str(item_collected))
			task_two_completed = true
	if docu_interaction == true and collect_documents == true:
		if Input.is_action_just_pressed("player_interact"):
			$"../DocumentsItem/DocumentsLocated".get_parent().queue_free() #the other items needs to swap their indicators to located
			item_collected = 3
			print("Item Collected: " + str(item_collected))
			task_three_completed = true
