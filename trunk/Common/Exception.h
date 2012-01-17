/********************************************************************
	创建时间:	4:1:2012   19:35
	文件名: 	f:\Aurorar\Core\Exception.h
	创建者:		丁亮
	
	文件作用:	异常处理
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "String.h"
#include <exception>


namespace Aurora
{
	class Exception : public std::exception
    {
    protected:
        long line;
        int number;
		String typeName;
        String description;
        String source;
        String file;
		mutable String fullDesc;
    public:

        enum ExceptionCodes 
		{
            ERR_CANNOT_WRITE_TO_FILE,
            ERR_INVALID_STATE,
            ERR_INVALIDPARAMS,
            ERR_RENDERINGAPI_ERROR,
            ERR_DUPLICATE_ITEM,
            ERR_ITEM_NOT_FOUND,
            ERR_FILE_NOT_FOUND,
            ERR_INTERNAL_ERROR,
            ERR_RT_ASSERTION_FAILED, 
			ERR_NOT_IMPLEMENTED
        };


        Exception( int number, const String& description, const String& source );

        Exception( int number, const String& description, const String& source, const char* type, const char* file, long line );

        Exception(const Exception& rhs);

		~Exception() throw() {}

        void operator = (const Exception& rhs);

        virtual const String& getFullDescription(void) const;

        virtual int getNumber(void) const throw();

        virtual const String &getSource() const { return source; }

        virtual const String &getFile() const { return file; }

        virtual long getLine() const { return line; }

		virtual const String &getDescription(void) const { return description; }

		const char* what() const throw() { return getFullDescription().c_str(); }
        
    };

	template <int num>
	struct ExceptionCodeType
	{
		enum { number = num };
	};

	class UnimplementedException : public Exception 
	{
	public:
		UnimplementedException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "UnimplementedException", inFile, inLine) {}
	};
	class FileNotFoundException : public Exception
	{
	public:
		FileNotFoundException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "FileNotFoundException", inFile, inLine) {}
	};
	class IOException : public Exception
	{
	public:
		IOException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "IOException", inFile, inLine) {}
	};
	class InvalidStateException : public Exception
	{
	public:
		InvalidStateException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "InvalidStateException", inFile, inLine) {}
	};
	class InvalidParametersException : public Exception
	{
	public:
		InvalidParametersException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "InvalidParametersException", inFile, inLine) {}
	};
	class ItemIdentityException : public Exception
	{
	public:
		ItemIdentityException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "ItemIdentityException", inFile, inLine) {}
	};
	class InternalErrorException : public Exception
	{
	public:
		InternalErrorException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "InternalErrorException", inFile, inLine) {}
	};
	class RenderingAPIException : public Exception
	{
	public:
		RenderingAPIException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "RenderingAPIException", inFile, inLine) {}
	};
	class RuntimeAssertionException : public Exception
	{
	public:
		RuntimeAssertionException(int inNumber, const String& inDescription, const String& inSource, const char* inFile, long inLine)
			: Exception(inNumber, inDescription, inSource, "RuntimeAssertionException", inFile, inLine) {}
	};

	class ExceptionFactory
	{
	private:
		ExceptionFactory() {}
	public:
		static UnimplementedException create(
			ExceptionCodeType<Exception::ERR_NOT_IMPLEMENTED> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return UnimplementedException(code.number, desc, src, file, line);
		}
		static FileNotFoundException create(
			ExceptionCodeType<Exception::ERR_FILE_NOT_FOUND> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return FileNotFoundException(code.number, desc, src, file, line);
		}
		static IOException create(
			ExceptionCodeType<Exception::ERR_CANNOT_WRITE_TO_FILE> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return IOException(code.number, desc, src, file, line);
		}
		static InvalidStateException create(
			ExceptionCodeType<Exception::ERR_INVALID_STATE> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return InvalidStateException(code.number, desc, src, file, line);
		}
		static InvalidParametersException create(
			ExceptionCodeType<Exception::ERR_INVALIDPARAMS> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return InvalidParametersException(code.number, desc, src, file, line);
		}
		static ItemIdentityException create(
			ExceptionCodeType<Exception::ERR_ITEM_NOT_FOUND> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return ItemIdentityException(code.number, desc, src, file, line);
		}
		static ItemIdentityException create(
			ExceptionCodeType<Exception::ERR_DUPLICATE_ITEM> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return ItemIdentityException(code.number, desc, src, file, line);
		}
		static InternalErrorException create(
			ExceptionCodeType<Exception::ERR_INTERNAL_ERROR> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return InternalErrorException(code.number, desc, src, file, line);
		}
		static RenderingAPIException create(
			ExceptionCodeType<Exception::ERR_RENDERINGAPI_ERROR> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return RenderingAPIException(code.number, desc, src, file, line);
		}
		static RuntimeAssertionException create(
			ExceptionCodeType<Exception::ERR_RT_ASSERTION_FAILED> code, 
			const String& desc, 
			const String& src, const char* file, long line)
		{
			return RuntimeAssertionException(code.number, desc, src, file, line);
		}

	};
	

	
#ifndef AURORA_EXCEPT
#define AURORA_EXCEPT(num, desc, src) throw Aurora::ExceptionFactory::create( \
	Aurora::ExceptionCodeType<num>(), desc, src, __FILE__, __LINE__ );
#endif

}
