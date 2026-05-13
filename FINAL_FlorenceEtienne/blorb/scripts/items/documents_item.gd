extends RigidBody3D

@onready var documents_indicator: Label3D = $"../DocumentsItem/DocumentsIndicator"

func _ready() -> void:
	documents_indicator.visible = false
	get_tree().get_first_node_in_group("player").connect("collected_item", Callable(self, "_on_collectable_item"))
	
func _on_collectable_item():
	documents_indicator.visible = true
