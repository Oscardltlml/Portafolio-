from flask import Flask, jsonify, request
from zeep import Client

app = Flask(__name__)

# API REST
@app.route('/api/data', methods=['GET'])
def get_data():
    return jsonify({'message': 'Hola desde la API REST, Oscar Aguilera!'})

@app.route('/api/data/<int:number>', methods=['GET'])
def get_number_square(number):
    square = number ** 2
    return jsonify({'number': number, 'square': square})

# Llamada SOAP
@app.route('/api/soap', methods=['GET'])
def call_soap():
    url = 'http://www.dneonline.com/calculator.asmx?WSDL'  # Ejemplo de WSDL
    client = Client(url)
    result = client.service.Add(5, 3)  # Llama a la operación 'Add'
    return jsonify({'result': result})

if __name__ == '__main__':
    app.run(debug=True)
