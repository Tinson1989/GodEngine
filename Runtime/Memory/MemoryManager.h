#pragma once

#include "Allocator.h"
#include "Runtime/Interface/IModule.h"
#include "Runtime/Utilities/Singleton.h"

namespace GodEngine {
	class MemoryManager : public IModule {
	public:

		template<class T, typename... Arguments>
		T* New(Arguments... parameters)
		{
			return new (Allocate(sizeof(T))) T(parameters...);
		}

		template<class T>
		void Delete(T* p)
		{
			p->~T();
			Free(p, sizeof(T));
		}
		MemoryManager();
		virtual ~MemoryManager();
		virtual int Initialize() noexcept;
		virtual void Finalize() noexcept;

		void* Allocate(size_t size);
		void Free(void* p, size_t size);

	private:
		MemoryManager(const MemoryManager& m) = default;
		MemoryManager& operator=(const MemoryManager&) = default;

		static size_t* m_pBlockSizeLookup;
		static Allocator * m_pAllocators;
		static Allocator* LookupAllocator(size_t size);
		friend class Singleton<MemoryManager>;
	};

	typedef Singleton<MemoryManager> GMemoryManager;

}
