import requests
import json
from time import sleep

# currently assumes the file is in the home directory
filename = r"status.txt"

def retreive_data(filename):
	f = open(filename, 'r')
	# decide data format. i recommend json here too.
	# then you can just use:
	raw_data = f.read()
	#print (raw_data)
	
	system_start = int(raw_data.split(" ")[0])
	system_pause = int(raw_data.split(" ")[1])
	motor_pause = int(raw_data.split(" ")[2])
	track_number = int(raw_data.split(" ")[3])
	volume = int(raw_data.split(" ")[4])
	glass_distance = int(raw_data.split(" ")[5])
	light_lux = float(raw_data.split(" ")[6])

	f.close()

	return [system_start, system_pause, motor_pause, track_number, volume, glass_distance, light_lux]


def send_to_mongo(system_start, system_pause, motor_pause, track_number, volume, glass_distance, light_lux):
	mongoID = "DjDKE7adIsCNxYsls6ItXSR67DquF-11"
	url = 'https://api.mongolab.com/api/1/databases/musiclab/collections/sensor_data?apiKey=' + mongoID
	headers = {'Content-type': 'application/json', 'Accept': 'text/plain'}
	#data = {'_id':{"$oid":'56b94f2fe4b0a81ce3fe22f7'}, 'system_start':system_start, 'system_pause':system_pause, 'motor_pause':motor_pause, 'track_number':track_number, 'volume': volume, 'glass_distance':glass_distance, 'light_lux':light_lux}
	data = {'system_start':system_start, 'system_pause':system_pause, 'motor_pause':motor_pause, 'track_number':track_number, 'volume': volume, 'glass_distance':glass_distance, 'light_lux':light_lux}
	data_json = json.dumps(data)
	#response = requests.put(url, data = data_json, headers = headers )
	response = requests.post(url, data = data_json, headers = headers )

	print (response.content)

# Continuously push the data back to database
while True:
	[system_start, system_pause, motor_pause, track_number, volume, glass_distance, light_lux] = retreive_data(filename)
	send_to_mongo(system_start, system_pause, motor_pause, track_number, volume, glass_distance, light_lux)

	sleep(2)