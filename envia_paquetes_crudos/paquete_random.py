from scapy.all import Ether, sendp

# Dirección MAC de destino
dst_mac = "ff:ff:ff:ff:ff:ff"  # Dirección de broadcast, por ejemplo

# Datos aleatorios a insertar después de la MAC de destino
random_data = b"\x01\x02\x03\x04\x05\x06\x07\x08"

# Crear paquete Ethernet
packet = Ether(dst=dst_mac, type=0x0800) / random_data

# Mostrar detalles del paquete
packet.show()

# Enviar el paquete
sendp(packet, iface="wlp7s0")
