

#include "buffer.h"



BufferState_t buffer_store(Buffer_t* buf , Packet_t* packet)
{
	if( buf->in_index  == buf->out_index + 1 )
	{
		return BUFFER_FULL;
	}
	
	buf->arr[buf->in_index % 50] = *packet;
	
	buf->in_index = (buf->in_index + 1) % 50;
	return BUFFER_SUCCESS;

}
BufferState_t buffer_restore(Buffer_t* buf , Packet_t* packet)
{
	if( buf->in_index  == buf->out_index  )
	{
		return BUFFER_EMPTY;
	}
	
	buf->out_index = (buf->out_index + 1) % 50;
	*packet = buf->arr[buf->out_index % 50];
	return BUFFER_SUCCESS;
}