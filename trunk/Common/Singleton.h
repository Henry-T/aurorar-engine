/********************************************************************
	创建时间:	4:1:2012   11:16
	文件名: 	f:\Aurorar\Core\Singleton.h
	创建者:		丁亮
	
	文件作用:	单例模式
*********************************************************************/
#pragma once

#pragma warning (disable : 4311)
#pragma warning (disable : 4312)

namespace Aurora 
{
    template <typename T> 
	class Singleton
    {
	private:
		/** \brief Explicit private copy constructor. This is a forbidden operation.*/
		Singleton(const Singleton<T> &);

		/** \brief Private operator= . This is a forbidden operation. */
		Singleton& operator=(const Singleton<T> &);
    
	protected:
        static T* ms_Singleton;

    public:
        Singleton( void )
        {
            assert( !ms_Singleton );
#if defined( _MSC_VER ) && _MSC_VER < 1200	 
            int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
            ms_Singleton = (T*)((int)this + offset);
#else
	    ms_Singleton = static_cast< T* >( this );
#endif
        }
        ~Singleton( void )					{ assert( ms_Singleton );  ms_Singleton = 0;			}
        static T& getSingleton( void )		{ assert( ms_Singleton );  return ( *ms_Singleton );	}
        static T* getSingletonPtr( void )	{ return ms_Singleton; }
    };

}
