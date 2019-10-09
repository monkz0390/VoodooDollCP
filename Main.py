#CP LIB set up
import time
from adafruit_circuitplayground.express import cpx
#call neopixel lib 
#call speaker lib
#call accelerometer lib

#number of skin layers

  #layer_a set up
import digitalio 
import board
layer_a = digitalio.DigitalInOut(board.BUTTON_A)
layer_a.direction = digitalio.Direction.INPUT


  #layer_b set up
import digitalio 
import board
layer_b = digitalio.DigitalInOut(board.BUTTON_A)
layer_b.direction = digitalio.Direction.INPUT

  #layer_c set up
import digitalio 
import board
layer_c = digitalio.DigitalInOut(board.BUTTON_A)
layer_c.direction = digitalio.Direction.INPUT


#heart kill spot set up
import digitalio 
import board
heart = digitalio.DigitalInOut(board.BUTTON_A) 
heart.direction = digitalio.Direction.INPUT

#pain function
def pain():
  print("pain")
#agony function
def agony():
  print("agony")
#death function
def death():
  print("death")
  
#main code loop
while True:
  
  print("alive")
  #normal face
  
