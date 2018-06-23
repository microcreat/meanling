from django.urls import path
from . import views

urlpatterns = [
	path('index', views.index, name='index'),
	path('comm_process', views.comm_process, name='comm_process'),
	path('addarticle', views.addarticle, name='addarticle'),
	path('delarticle/(?P<id>[0-9]+)', views.delarticle, name='delarticle')
]
