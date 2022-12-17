# from ctypes import *

# # Carga de la libreria
# libosa = cdll.LoadLibrary('./pro.dll')
# print('well')
import ctypes

# Load DLL into memory.

hllDll = ctypes.WinDLL ("./pro.dll")