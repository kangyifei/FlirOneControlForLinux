#ifndef C_FLIR_ONE_DRIVER_H
#define C_FLIR_ONE_DRIVER_H

//****************************************************************************************************
//Класс подключения к драйверам Flir One
//****************************************************************************************************

//****************************************************************************************************
//подключаемые библиотеки
//****************************************************************************************************
#include <stdint.h>
#include "libusb.h"

//****************************************************************************************************
//макроопределения
//****************************************************************************************************

//****************************************************************************************************
//константы
//****************************************************************************************************

//****************************************************************************************************
//предварительные объявления
//****************************************************************************************************

//****************************************************************************************************
//Класс подключения к драйверам Flir One
//****************************************************************************************************
class CFlirOneDriver
{
 public:
  //-перечисления---------------------------------------------------------------------------------------
  //-структуры------------------------------------------------------------------------------------------
  //-константы------------------------------------------------------------------------------------------
  static const size_t VENDOR_ID=0x09cb;//идентификатор производителя
  static const size_t PRODUCT_ID=0x1996;//индентификатор устройства  
 private:
  //-переменные-----------------------------------------------------------------------------------------
  libusb_device_handle *USBDeviceHandle;//дескриптор устройства
  bool Ready;//готовность к приёму данных
 public:
  //-конструктор----------------------------------------------------------------------------------------
  CFlirOneDriver(void);
  //-деструктор-----------------------------------------------------------------------------------------
  ~CFlirOneDriver();
 public:
  //-открытые функции-----------------------------------------------------------------------------------
  bool Open(void);//подключиться к устройству
  void Close(void);//отключиться от устройства
  bool ReadStream(uint8_t* ptr,uint32_t &size);//чтение данных из устройств
 private:
  //-закрытые функции-----------------------------------------------------------------------------------  
  bool InitFlirOne(void);//инициализация Flir One
  bool ConnectToFlirOne(void);//подключение к Flir One
};

#endif
