
extends Node2D

# member variables here, example:
# var a=2
# var b="textvar"

var screen_size
var pad_size

func _ready():
	# Initalization here
	screen_size = get_viewport_rect().size
	pad_size = get_node("left").get_texture().get_size()
	set_process(true)

var ball_speed = 80
var direction = Vector2(-1,0)
const PAD_SPEED = 150

func _process(delta):
	var ball_pos = get_node("ball").get_pos()
	var left_rect = Rect2 ( get_node("left").get_pos() - pad_size/2, pad_size )
	var right_rect = Rect2 ( get_node("right").get_pos() - pad_size/2, pad_size )
	ball_pos+=direction*ball_speed*delta
	
	if ( (ball_pos.y<0 and direction.y<0) or (ball_pos.y>screen_size.y and direction.y>0)):
		direction.y = -direction.y
	
	if( (left_rect.has_point(ball_pos) and direction.x < 0) or (right_rect.has_point(ball_pos) and direction.x > 0) ):
		direction.x = -direction.x
		ball_speed*=1.1
		direction.y = randf()*2.0-1
		direction = direction.normalized()
	
	if (ball_pos.x < 0 or ball_pos.x > screen_size.x):
		ball_pos=screen_size*0.5
		ball_speed = 80
		direction=Vector2(-1,0)
	
	get_node("ball").set_pos(ball_pos)
	
	var left_pos=get_node("left").get_pos()
	
	if (left_pos.y>0 and Input.is_action_pressed("left_move_up")):
		left_pos.y+=-PAD_SPEED*delta
	
	if(left_pos.y<screen_size.y and Input.is_action_pressed("left_move_down")):
		left_pos.y+=PAD_SPEED*delta
	
	get_node("left").set_pos(left_pos)
	
	var right_pos=get_node("right").get_pos()
	
	if (right_pos.y > 0 and Input.is_action_pressed("right_move_up")):
		right_pos.y+=-PAD_SPEED*delta
	if (right_pos.y < screen_size.y and Input.is_action_pressed("right_move_down")):
		right_pos.y+=PAD_SPEED*delta
	
	get_node("right").set_pos(right_pos)