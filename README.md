# sensorMesh
Arduino IDE ESP8266 Mesh network for sensors to log data to the Internet.

The plan for this project is to create a way of easily setting up a mesh network with a root node that can connect to the internet allowing remote sensors too far from the networked access point a way of posting their readings.

The planned features for this is to be able to have all nodes in the mesh run the same source code regardless of whether they are a root, branch or leaf node and for the network to automatically reconfigure so all nodes have a route to the root.

Planned API’s will be a sendBroadcastMessage, sendMessage, sendRoot, handleMessage

This was inspired by easyMesh by Coopdis https://github.com/Coopdis/easyMesh and the fact my wireless temperature logger doesn’t get any signal in the garage.
