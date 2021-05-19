#pragma once

#include "DLL.h"
#include "Core.h"
#include <utility>
#include <new>
#include <functional>
#include <cstddef>

namespace Impara
{
	typedef unsigned char byte;
	typedef uint32_t marker;

	class IMPARA_API ImparaAllocator
	{
	public:
		// bytes
		ImparaAllocator(uint32_t bufferSize, uint32_t tempBufferSize);
		~ImparaAllocator();

		// bytes
		void* Allocate(uint32_t size);
		// bytes
		template <typename T>
		void* AlignedAllocation(uint32_t size=alignof(T));
	private:
		marker m_CurrentMarker = 0;
		byte* m_TempBuffer = nullptr;
		byte* m_Buffer = nullptr;
		uint32_t m_BufferSize = 0;
		uint32_t m_TempBufferSize = 0;
	};
}