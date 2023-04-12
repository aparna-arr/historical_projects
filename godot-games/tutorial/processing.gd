
extends Label

# member variables here, example:
# var a=2
# var b="textvar"

var accum=0

func _ready():
	# Initalization here
	set_process(true)

func _process(delta):
	accum+=delta
	set_text(str(accum))


