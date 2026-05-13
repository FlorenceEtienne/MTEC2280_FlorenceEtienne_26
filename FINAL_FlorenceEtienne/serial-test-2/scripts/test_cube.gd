extends CharacterBody3D

var cube_scene = load("res://scenes/test_cube.tscn")
var cube_spawn = false
var direction_x = 0
var direction_y = 0
var direction_z = 0

const speed = 10.5
const jump = 10

var gravity = ProjectSettings.get_setting("physics/3d/default_gravity")

func _physics_process(delta: float) -> void:
	#camera rotation
	#if Input.is_action_pressed("player_left"):
		#$CameraController.rotate_y(deg_to_rad(2.5))
	#if Input.is_action_pressed("player_right"):
		#$CameraController.rotate_y(deg_to_rad(-2.5))
		#
	##jump
	#if Input.is_action_just_pressed("player_jump") and is_on_floor():
		#velocity.y = jump
	#if not is_on_floor():
		#velocity.y -= gravity * delta
		
	#direction of player's movements
	#var input_dir = Input.get_vector("player_left","player_right","player_forward","player_backward")
	#var direction = ($CameraController.transform.basis * Vector3(input_dir.x, 0, input_dir.y)).normalized()
	#
	#if direction:
		#velocity.x = direction.x * speed
		#velocity.z = direction.z * speed
	#else:
		#velocity.x = move_toward(velocity.x, 0, speed)
		#velocity.z = move_toward(velocity.z, 0, speed)
		#
	#move_and_slide()
	
	velocity.x = move_toward(velocity.x, direction_x, speed)
	velocity.z = move_toward(velocity.z, direction_z, speed)
	
	#if Input.is_action_just_pressed("player_jump") and is_on_floor():
		#velocity.y = jump
	#if not is_on_floor():
		#velocity.y -= gravity * delta
	#if jump && is_on_floor():
		#velocity.y = gravity
	
	move_and_slide()
	
	#camera movements
	$CameraController.position = position

func _spawn_cube():
	if Input.is_action_just_pressed("ui_accept"):
		cube_spawn = !cube_spawn
		cube_scene = get_tree().instantiate()
		add_child(cube_scene)
	
func _move_direction(left, right, forward, backward) -> void:
	if left == 1:
		direction_x = -1
		$CameraController.rotate_y(deg_to_rad(2.5))
	elif right == 1:
		direction_x = 1
		$CameraController.rotate_y(deg_to_rad(-2.5))
	elif left == 0 and right == 0:
		direction_x = 0
		$CameraController.rotate_y(deg_to_rad(0))
	
	if forward == 1:
		direction_z = -1
	elif backward == 1:
		direction_z = 1
	elif forward == 0 and backward == 0:
		direction_z = 0
