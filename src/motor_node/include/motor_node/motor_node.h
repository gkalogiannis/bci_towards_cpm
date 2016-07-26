#ifndef MOTOR_NODE_MOTOR_NODE_H
#define MOTOR_NODE_MOTOR_NODE_H

#include <iostream>
#include "Definitions.h"
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <math.h>
#include "ros/ros.h"

typedef void* HANDLE;
typedef int BOOL;

using namespace std;

void* g_pKeyHandle = 0;
unsigned short g_usNodeId = 1;
string g_deviceName;
string g_protocolStackName;
string g_interfaceName;
string g_portName;
int g_baudrate = 0;

const string g_programName = "motor_node_node";

#ifndef MMC_SUCCESS
        #define MMC_SUCCESS 0
#endif

#ifndef MMC_FAILED
        #define MMC_FAILED 1
#endif

#ifndef MMC_MAX_LOG_MSG_SIZE
        #define MMC_MAX_LOG_MSG_SIZE 512
#endif

void  LogError(string functionName, int p_lResult, unsigned int p_ulErrorCode);
void  LogInfo(string message);
void  PrintUsage();
void  PrintHeader();
void  PrintSettings();
int   OpenDevice(unsigned int* p_pErrorCode);
int   CloseDevice(unsigned int* p_pErrorCode);
void  SetDefaultParameters();
int   ParseArguments(int argc, char** argv);
int   DemoProfilePositionMode(HANDLE p_DeviceHandle, unsigned short p_usNodeId, unsigned int & p_rlErrorCode);
int   Demo(unsigned int* p_pErrorCode);
int   PrepareDemo(unsigned int* p_pErrorCode);

#endif //MOTOR_NODE_MOTOR_NODE_H
