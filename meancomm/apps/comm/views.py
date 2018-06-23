from django.shortcuts import render, HttpResponse
from django.core.wsgi import get_wsgi_application

# Create your views here.
from django.views.decorators.csrf import csrf_exempt
from django.http import HttpRequest, HttpResponse, HttpResponseRedirect
from json import loads, dumps

import MySQLdb
import json
import requests

from datetime import date
from comm.models import Article
import re

def index(request):
		titles=Article.objects.all()
		return render(request, 'comm/index.html', {'titles':titles})

def comm_process(request):                       
    resp = {'errorcode': 100, 'detail': 'Get success'}
    if request.method == 'GET':
        return HttpResponse(json.dumps(resp), content_type="application/json", status="201" )
    elif request.method == 'POST':
        story_data=request.body.decode('utf-8')
        name=story_data.index('name')       
        notes=story_data.index('notes')           
        name=re.findall(r"name=(\w+)",story_data)     
        notes=re.findall(r"notes=(\w+)",story_data)
        addarticle=Article()
        addarticle.title=name[0]
        addarticle.content=notes[0]
        addarticle.save()
        #return HttpResponse("Welcome to the page at %s" %request.body)
        return HttpResponseRedirect('/comm/index')

def addarticle(request):
        addarticle=Article()
        addarticle.title='mean'
        addarticle.content='mean'
        addarticle.save()
        return HttpResponseRedirect('/comm/index')

def delarticle(request, id):
        dart=Article.objects.get(id=int(id))
        dart.delete()
        return HttpResponseRedirect('/comm/index')

