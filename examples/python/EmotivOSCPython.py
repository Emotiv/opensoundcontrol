"""Small example Emotiv OSC

This program listens to several addresses, and prints some information about
received packets.
"""

import argparse
import math

from pythonosc import dispatcher
from pythonosc import osc_server

PORT_NUMBER = 8000
IP_DEFAULT = "127.0.0.1"

def filter_handler(address,*args):
  print(f"{address}: {args}")

if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--ip",
      default=IP_DEFAULT, help="The ip to listen on")
  parser.add_argument("--port",
      type=int, default=PORT_NUMBER, help="The port to listen on")
  args = parser.parse_args()

  dispatcher = dispatcher.Dispatcher()
  
  #=== Facial Expressions Eye
  dispatcher.map("/fac/eyeAct/lookL", filter_handler)
  dispatcher.map("/fac/eyeAct/lookR", filter_handler)
  dispatcher.map("/fac/eyeAct/blink", filter_handler)
  dispatcher.map("/fac/eyeAct/winkL", filter_handler)
  dispatcher.map("/fac/eyeAct/winkR", filter_handler)

  #=== Facial Expressions Upperface
  dispatcher.map("/fac/uAct/neutral", filter_handler)
  dispatcher.map("/fac/uAct/frown", filter_handler)
  dispatcher.map("/fac/uAct/surprise", filter_handler)

  #=== Facial Expressions Lowerface
  dispatcher.map("/fac/lAct/neutral", filter_handler)
  dispatcher.map("/fac/lAct/clench", filter_handler)
  dispatcher.map("/fac/lAct/laugh", filter_handler)
  dispatcher.map("/fac/lAct/smile", filter_handler)
  dispatcher.map("/fac/lAct/smirkLeft", filter_handler)
  dispatcher.map("/fac/lAct/smirkRight", filter_handler)

  #=== Mental Commands
  dispatcher.map("/com/neutral", filter_handler)
  dispatcher.map("/com/push", filter_handler)
  dispatcher.map("/com/pull", filter_handler)
  dispatcher.map("/com/left", filter_handler)
  dispatcher.map("/com/right", filter_handler)
  dispatcher.map("/com/lift", filter_handler)
  dispatcher.map("/com/drop", filter_handler)
  dispatcher.map("/com/rotateLeft", filter_handler)
  dispatcher.map("/com/rotateRight", filter_handler)
  dispatcher.map("/com/rotateClockwise", filter_handler)
  dispatcher.map("/com/rotateCounterClockwise", filter_handler)
  dispatcher.map("/com/rotateForwards", filter_handler)
  dispatcher.map("/com/rotateReverse", filter_handler)
  dispatcher.map("/com/disappear", filter_handler)

  #=== Performance Metrics
  dispatcher.map("/met/foc", filter_handler)
  dispatcher.map("/met/int", filter_handler)
  dispatcher.map("/met/rel", filter_handler)
  dispatcher.map("/met/str", filter_handler)
  dispatcher.map("/met/exc", filter_handler)
  dispatcher.map("/met/eng", filter_handler)
  dispatcher.map("/met/cognitiveStress", filter_handler)
  dispatcher.map("/met/visualAttention", filter_handler)
  dispatcher.map("/met/auditoryAttention", filter_handler)


  server = osc_server.ThreadingOSCUDPServer(
      (args.ip, args.port), dispatcher)
  print("Serving on {}".format(server.server_address))
  server.serve_forever()