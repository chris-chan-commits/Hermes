#include "ImparaAllocator.h"

namespace Impara
{

	ImparaAllocator::ImparaAllocator(uint32_t bufferSize, uint32_t tempBufferSize):
		m_BufferSize(bufferSize), m_TempBufferSize(tempBufferSize)
	{
		// Allocate the stack, and the temporary buffer
		m_Buffer = (byte*)malloc(bufferSize);
		m_TempBuffer = (byte*)malloc(tempBufferSize);
	}
	ImparaAllocator::~ImparaAllocator()
	{
	}
	void* ImparaAllocator::Allocate(uint32_t size)
	{
		// If the position in the stack, and the size of the allocation, reach outside the bounds of the stack size
		// Then warn the user, and reallocate the buffer size
		// However, the reallocation only reallocates to the size of the allocation
		// So, any new allocations, are going to be reallocating constantly
		if (m_CurrentMarker + size > m_BufferSize)
		{
			std::cerr << "Warning! Stack out of range! Please increase the stack size!\nReallocating to prevent potential errors..." << std::endl;
			m_Buffer = (byte*)realloc(m_Buffer, m_CurrentMarker + size);
		}

		// Similar to the previous if statement
		if (m_TempBufferSize < size)
		{
			std::cerr << "Warning! Temporary buffer out of range! Please increase the temporary buffer size!\nReallocating to prevent potential errors..." << std::endl;
			m_TempBuffer = (byte*)realloc(m_TempBuffer, size);
		}

		// Copy the block of memory from the stack, into the temporary buffer
		memcpy(m_TempBuffer, m_Buffer + m_CurrentMarker, size);

		// Increment the stack position
		m_CurrentMarker += size;

		return m_TempBuffer;
	}

	template <typename T>
	void* ImparaAllocator::AlignedAllocation(uint32_t size)
	{
		void* alloc = Allocate(size);
		if (std::align(size, sizeof(T), alloc, m_BufferSize))
		{
			return alloc;
		}
		return nullptr;
	}
}