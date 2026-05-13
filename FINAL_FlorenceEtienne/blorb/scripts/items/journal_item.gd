extends RigidBody3D

@onready var journal_located: Label3D = $"../JournalItem/JournalLocated"

func _ready() -> void:
	journal_located.visible = false
	get_tree().get_first_node_in_group("player").connect("collected_item", Callable(self, "_on_collectable_item"))
	
func _on_collectable_item():
	journal_located.visible = true
