import requests
import json
import urllib
import http.client

url='http://139.159.162.170:3006/comm/comm_process'

data = {
        'id': '100',
        'name': 'microcreat',
        'notes': 'test_code!'
        }
headers = {'content-type': 'application/json',
           }
 
ret = requests.post(url, data=data, headers=headers)
print(ret.url)
print(ret.text)
