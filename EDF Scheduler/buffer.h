

#ifndef __BUFFER_INCLUDE_H_
#define __BUFFER_INCLUDE_H_

typedef unsigned char uint8;

typedef enum
{
	BUFFER_EMPTY,
	BUFFER_FULL,
	BUFFER_SUCCESS
} BufferState_t;

typedef struct
{
	char* message;
	uint8 message_length;
}Packet_t;

typedef struct 
{
	uint8 in_index;
	uint8 out_index;
	Packet_t arr[50];
} Buffer_t;

BufferState_t buffer_store(Buffer_t* buf , Packet_t* packet);
BufferState_t buffer_restore(Buffer_t* buf , Packet_t* packet);

#endif