#!/usr/bin/env python
#import mraa
import random
import requests
import json
from time import sleep


def get_cmddata_mongo(collection, documentid):
    mongoID = "DjDKE7adIsCNxYsls6ItXSR67DquF-11"
    url = 'https://api.mongolab.com/api/1/databases/musiclab/collections/'+ collection + '/' + documentid + '?apiKey=' + mongoID
    
    print
    print
    print url
    response = requests.get(url)
    json_reponse = response.json()
    print "json_reponse"
    print json_reponse
    return json_reponse["command_value"]


def get_musicdata_mongo(collection, documentid):
    mongoID = "DjDKE7adIsCNxYsls6ItXSR67DquF-11"
    url = 'https://api.mongolab.com/api/1/databases/musiclab/collections/'+ collection + '/' + documentid + '?apiKey=' + mongoID
    
    print
    print
    print url
    response = requests.get(url)
    json_reponse = response.json()
    print "json_reponse"
    print json_reponse
    return json_reponse["track_id"]

'''
print (mraa.getVersion())
servo0 = mraa.Pwm(3)
servo0.period_us(700)
servo0.enable(True)
value= 0.0

servo1 = mraa.Pwm(5)
servo2 = mraa.Pwm(6)
buzzer0 = mraa.Pwm(9)
'''
track = 0
while True:
    #value = get_data_mongo("servo1", "56ac05a0e4b0b133d46d0e65")
    #print value
    target = open("control.txt", 'w')
    value = get_cmddata_mongo("control_play", "56aeaaf9e4b0102fef23e1d1")
    print value
    if value == 1:
                track = get_musicdata_mongo("music", "56ad3e1de4b0b133d46d1f42")
                print track
    
    #servo1.write(value)
    target.write(str(value))
    target.write(" ")
    target.write(str(track))
    target.write("\n")
    target.close()
    sleep(5)
    
