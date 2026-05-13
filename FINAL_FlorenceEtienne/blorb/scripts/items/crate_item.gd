extends RigidBody3D

@onready var crate_located: Label3D = $"../CrateItem/CrateLocated"

func _ready() -> void:
	crate_located.visible = false
	get_tree().get_first_node_in_group("player").connect("collected_item", Callable(self, "_on_collectable_item"))
	
func _on_collectable_item():
	crate_located.visible = true
	
