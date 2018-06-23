from wsgiref.simple_server import make_server

def application(env, start_response):
    data = 'www.meancomm.com!\n'
    status = '200 OK'
    response_headers=[('Content-Type', 'text/plain'), ('Content-Length', str(len(data)))]
    start_response(status, response_headers)
    return [b'<h1>Hello, web!</h1>']

