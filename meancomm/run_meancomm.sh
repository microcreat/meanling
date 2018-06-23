#!/bin/sh

#nohup uwsgi --http-socket :3005 --chdir /workdir/meanling/meancomm --module /workdir/meanling/meancomm/meancomm/wsgi.py  --wsgi-file /workdir/meanling/meancomm/comm.py > /workdir/meanling/meancomm/meancomm.out 2>&1 &
nohup gunicorn -w 3 -k gevent -b :3006 meancomm.wsgi:application > /workdir/meanling/meancomm/log/meancomm.out 2>&1 &

