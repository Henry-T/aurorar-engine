#include <windows.h>
#include <string>
#include <shlwapi.h>
#include <tchar.h>
#undef _tprintf
#include "WheatyExceptionReport.h"

#pragma warning ( push )
#pragma warning ( disable : 4715 )
#pragma warning ( disable : 4311 )
#pragma warning ( disable : 4312 )
#pragma warning ( disable : 4996 )

std::string g_strReport;
void	Report( const char* pszString, ... )
{
	char szMessage[1024];
	va_list	va;
	va_start( va, pszString );
	wvnsprintf( szMessage, sizeof(szMessage)-1, pszString, va );
	va_end( va );
	g_strReport += szMessage;
}
//============================== Global Variables =============================

//
// Declare the static variables of the WheatyExceptionReport class
//
TCHAR WheatyExceptionReport::m_szLogFileName[MAX_PATH];
LPTOP_LEVEL_EXCEPTION_FILTER WheatyExceptionReport::m_previousFilter;
HANDLE WheatyExceptionReport::m_hReportFile;
HANDLE WheatyExceptionReport::m_hProcess;
// Declare global instance of class
//WheatyExceptionReport g_WheatyExceptionReport;

//============================== Class Methods =============================

WheatyExceptionReport::WheatyExceptionReport( )   // Constructor
{
    // Install the unhandled exception filter function
    m_previousFilter =
        SetUnhandledExceptionFilter(WheatyUnhandledExceptionFilter);

    // Figure out what the report file will be named, and store it away
    GetModuleFileName( 0, m_szLogFileName, MAX_PATH );

    // Look for the '.' before the "EXE" extension.  Replace the extension
    // with "RPT"
    PTSTR pszDot = _tcsrchr( m_szLogFileName, _T('.') );
    if ( pszDot )
    {
        pszDot++;   // Advance past the '.'
        if ( _tcslen(pszDot) >= 3 )
            _tcscpy( pszDot, _T("RPT") );   // "RPT" -> "Report"
    }

    m_hProcess = GetCurrentProcess();
}

//============
// Destructor 
//============
WheatyExceptionReport::~WheatyExceptionReport( )
{
    SetUnhandledExceptionFilter( m_previousFilter );
}

//==============================================================
// Lets user change the name of the report file to be generated 
//==============================================================
void WheatyExceptionReport::SetLogFileName( PTSTR pszLogFileName )
{
    _tcscpy( m_szLogFileName, pszLogFileName );
}

//===========================================================
// Entry point where control comes on an unhandled exception 
//===========================================================
LONG WINAPI WheatyExceptionReport::WheatyUnhandledExceptionFilter(
                                    PEXCEPTION_POINTERS pExceptionInfo )
{
    m_hReportFile = CreateFile( m_szLogFileName,
                                GENERIC_WRITE,
                                0,
                                0,
                                OPEN_ALWAYS,
                                FILE_FLAG_WRITE_THROUGH,
                                0 );

    if ( m_hReportFile )
    {
        SetFilePointer( m_hReportFile, 0, 0, FILE_END );

        GenerateExceptionReport( pExceptionInfo );

        CloseHandle( m_hReportFile );
        m_hReportFile = 0;
    }
	MessageBox( 0, g_strReport.c_str(), "�쳣", MB_OK|MB_ICONERROR );
	FILE* fp = fopen( "execptionprport.rpt", "w" );
	if( fp )
	{
		fprintf( fp, g_strReport.c_str() );
		fclose( fp );
	}

    if ( m_previousFilter )
        return m_previousFilter( pExceptionInfo );
    else
        return EXCEPTION_CONTINUE_SEARCH;
}
 
//===========================================================================
// Open the report file, and write the desired information to it.  Called by 
// WheatyUnhandledExceptionFilter                                               
//===========================================================================
//void WheatyExceptionReport::GenerateExceptionReport(
//    PEXCEPTION_POINTERS pExceptionInfo )
//{
//
//
//
//    // Start out with a banner
//    _tprintf(_T("//=====================================================\r\n"));
//
//    PEXCEPTION_RECORD pExceptionRecord = pExceptionInfo->ExceptionRecord;
//
//#ifndef _DEBUG
//	// Luo_157 added 2004.09.26
//	CExceptionAddressToSrcLine e;
//	char szMapFilename[MAX_PATH];
//	GetModuleFileName( 0, szMapFilename, MAX_PATH );
//	PTSTR pszDot = _tcsrchr( szMapFilename, _T('.') );
//	if ( pszDot )
//	{
//		pszDot++;   // Advance past the '.'
//		if ( _tcslen(pszDot) >= 3 )
//			_tcscpy( pszDot, _T("map") );   // "RPT" -> "Report"
//		e.SetMapFilename( szMapFilename );
//		if( e.AddrToSrcLine( szMapFilename, (DWORD)pExceptionRecord->ExceptionAddress ) )
//		//if( e.AddrToSrcLine( szMapFilename, (DWORD)0x7C1581FD ) )
//		{
//			_tprintf(   _T("Exception Source File : %s\r\n" ), e.GetSrcFileDesc() );
//			_tprintf(   _T("Exception Source Line : %ld\r\n" ), e.GetSrcLine() );
//
//		}
//	}
//#endif
//
//	//////////////////////////////////////////////////////////////////////////
//	
//
//	
//	// First print information about the type of fault
//    _tprintf(   _T("Exception code: %08X %s\r\n"),
//                pExceptionRecord->ExceptionCode,
//                GetExceptionString(pExceptionRecord->ExceptionCode) );
//
//    // Now print information about where the fault occured
//    TCHAR szFaultingModule[MAX_PATH];
//    DWORD section, offset;
//    GetLogicalAddress(  pExceptionRecord->ExceptionAddress,
//                        szFaultingModule,
//                        sizeof( szFaultingModule ),
//                        section, offset );
//
//    _tprintf( _T("Fault address:  %08X %02X:%08X %s\r\n"),
//                pExceptionRecord->ExceptionAddress,
//                section, offset, szFaultingModule );
//
//    PCONTEXT pCtx = pExceptionInfo->ContextRecord;
//
//    // Show the registers
//    #ifdef _M_IX86  // X86 Only!
//    _tprintf( _T("\r\nRegisters:\r\n") );
//
//    _tprintf(_T("EAX:%08X\r\nEBX:%08X\r\nECX:%08X\r\nEDX:%08X\r\nESI:%08X\r\nEDI:%08X\r\n")
//            ,pCtx->Eax, pCtx->Ebx, pCtx->Ecx, pCtx->Edx,
//            pCtx->Esi, pCtx->Edi );
//
//    _tprintf( _T("CS:EIP:%04X:%08X\r\n"), pCtx->SegCs, pCtx->Eip );
//    _tprintf( _T("SS:ESP:%04X:%08X  EBP:%08X\r\n"),
//                pCtx->SegSs, pCtx->Esp, pCtx->Ebp );
//    _tprintf( _T("DS:%04X  ES:%04X  FS:%04X  GS:%04X\r\n"),
//                pCtx->SegDs, pCtx->SegEs, pCtx->SegFs, pCtx->SegGs );
//    _tprintf( _T("Flags:%08X\r\n"), pCtx->EFlags );
//
//    #endif
//
//    SymSetOptions( SYMOPT_DEFERRED_LOADS );
//
//    // Initialize DbgHelp
//    if ( !SymInitialize( GetCurrentProcess(), 0, TRUE ) )
//        return;
//
//    CONTEXT trashableContext = *pCtx;
//
//    WriteStackDetails( &trashableContext, false );
//
//    //#ifdef _M_IX86  // X86 Only!
//
//    //_tprintf( _T("========================\r\n") );
//    //_tprintf( _T("Local Variables And Parameters\r\n") );
//
//    //trashableContext = *pCtx;
//    //WriteStackDetails( &trashableContext, true );
//
//    //_tprintf( _T("========================\r\n") );
//    //_tprintf( _T("Global Variables\r\n") );
//
//    //SymEnumSymbols( GetCurrentProcess(),
//    //                (DWORD64)GetModuleHandle(szFaultingModule),
//    //                0, EnumerateSymbolsCallback, 0 );
//    //
//    //#endif      // X86 Only!
//
//    SymCleanup( GetCurrentProcess() );
//
//    _tprintf( _T("\r\n") );
//}
void WheatyExceptionReport::GenerateExceptionReport(
	PEXCEPTION_POINTERS pExceptionInfo )
{



	// Start out with a banner
	//Report(_T("//=====================================================\r\n"));

	PEXCEPTION_RECORD pExceptionRecord = pExceptionInfo->ExceptionRecord;

//#ifndef _DEBUG
	// Luo_157 added 2004.09.26
	CExceptionAddressToSrcLine e;
	char szMapFilename[MAX_PATH];
	GetModuleFileName( 0, szMapFilename, MAX_PATH );
	PTSTR pszDot = _tcsrchr( szMapFilename, _T('.') );
	if ( pszDot )
	{
		pszDot++;   // Advance past the '.'
		if ( _tcslen(pszDot) >= 3 )
			_tcscpy( pszDot, _T("map") );   // "RPT" -> "Report"
		e.SetMapFilename( szMapFilename );
		if( e.AddrToSrcLine( szMapFilename, (DWORD)pExceptionRecord->ExceptionAddress ) )
			//if( e.AddrToSrcLine( szMapFilename, (DWORD)0x7C1581FD ) )
		{
			Report(   _T("Exception Source File : %s\r\n" ), e.GetSrcFileDesc() );
			Report(   _T("Exception Source Line : %ld\r\n" ), e.GetSrcLine() );

		}
	}
//#endif

	//////////////////////////////////////////////////////////////////////////



	// First print information about the type of fault
	Report(   _T("Exception code: %08X %s\r\n"),
		pExceptionRecord->ExceptionCode,
		GetExceptionString(pExceptionRecord->ExceptionCode) );

	// Now print information about where the fault occured
	TCHAR szFaultingModule[MAX_PATH];
	DWORD section, offset;
	GetLogicalAddress(  pExceptionRecord->ExceptionAddress,
		szFaultingModule,
		sizeof( szFaultingModule ),
		section, offset );

	Report( _T("Fault address:  %08X %02X:%08X %s\r\n"),
		pExceptionRecord->ExceptionAddress,
		section, offset, szFaultingModule );

	PCONTEXT pCtx = pExceptionInfo->ContextRecord;

	// Show the registers
#ifdef _M_IX86  // X86 Only!
	Report( _T("\r\nRegisters:\r\n") );

	Report(_T("EAX:%08X\r\nEBX:%08X\r\nECX:%08X\r\nEDX:%08X\r\nESI:%08X\r\nEDI:%08X\r\n")
		,pCtx->Eax, pCtx->Ebx, pCtx->Ecx, pCtx->Edx,
		pCtx->Esi, pCtx->Edi );

	Report( _T("CS:EIP:%04X:%08X\r\n"), pCtx->SegCs, pCtx->Eip );
	Report( _T("SS:ESP:%04X:%08X  EBP:%08X\r\n"),
		pCtx->SegSs, pCtx->Esp, pCtx->Ebp );
	Report( _T("DS:%04X  ES:%04X  FS:%04X  GS:%04X\r\n"),
		pCtx->SegDs, pCtx->SegEs, pCtx->SegFs, pCtx->SegGs );
	Report( _T("Flags:%08X\r\n"), pCtx->EFlags );

#endif

	SymSetOptions( SYMOPT_DEFERRED_LOADS );

	// Initialize DbgHelp
	if ( !SymInitialize( GetCurrentProcess(), 0, TRUE ) )
		return;

	CONTEXT trashableContext = *pCtx;

	WriteStackDetails( &trashableContext, false );

	//#ifdef _M_IX86  // X86 Only!

	//Report( _T("========================\r\n") );
	//Report( _T("Local Variables And Parameters\r\n") );

	//trashableContext = *pCtx;
	//WriteStackDetails( &trashableContext, true );

	//Report( _T("========================\r\n") );
	//Report( _T("Global Variables\r\n") );

	//SymEnumSymbols( GetCurrentProcess(),
	//                (DWORD64)GetModuleHandle(szFaultingModule),
	//                0, EnumerateSymbolsCallback, 0 );
	//
	//#endif      // X86 Only!

	SymCleanup( GetCurrentProcess() );

	Report( _T("\r\n") );
	//MessageBox( 0, g_strReport.c_str(), "", MB_OK );
}
//======================================================================
// Given an exception code, returns a pointer to a static string with a 
// description of the exception                                         
//======================================================================
LPTSTR WheatyExceptionReport::GetExceptionString( DWORD dwCode )
{
    #define EXCEPTION( x ) case EXCEPTION_##x: return _T(#x);

    switch ( dwCode )
    {
        EXCEPTION( ACCESS_VIOLATION )
        EXCEPTION( DATATYPE_MISALIGNMENT )
        EXCEPTION( BREAKPOINT )
        EXCEPTION( SINGLE_STEP )
        EXCEPTION( ARRAY_BOUNDS_EXCEEDED )
        EXCEPTION( FLT_DENORMAL_OPERAND )
        EXCEPTION( FLT_DIVIDE_BY_ZERO )
        EXCEPTION( FLT_INEXACT_RESULT )
        EXCEPTION( FLT_INVALID_OPERATION )
        EXCEPTION( FLT_OVERFLOW )
        EXCEPTION( FLT_STACK_CHECK )
        EXCEPTION( FLT_UNDERFLOW )
        EXCEPTION( INT_DIVIDE_BY_ZERO )
        EXCEPTION( INT_OVERFLOW )
        EXCEPTION( PRIV_INSTRUCTION )
        EXCEPTION( IN_PAGE_ERROR )
        EXCEPTION( ILLEGAL_INSTRUCTION )
        EXCEPTION( NONCONTINUABLE_EXCEPTION )
        EXCEPTION( STACK_OVERFLOW )
        EXCEPTION( INVALID_DISPOSITION )
        EXCEPTION( GUARD_PAGE )
        EXCEPTION( INVALID_HANDLE )
    }

    // If not one of the "known" exceptions, try to get the string
    // from NTDLL.DLL's message table.

    static TCHAR szBuffer[512] = { 0 };

    FormatMessage( FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_HMODULE,
                   GetModuleHandle( _T("NTDLL.DLL") ),
                   dwCode, 0, szBuffer, sizeof( szBuffer ), 0 );

    return szBuffer;
}

//=============================================================================
// Given a linear address, locates the module, section, and offset containing  
// that address.                                                               
//                                                                             
// Note: the szModule paramater buffer is an output buffer of length specified 
// by the len parameter (in characters!)                                       
//=============================================================================
BOOL WheatyExceptionReport::GetLogicalAddress(
        PVOID addr, PTSTR szModule, DWORD len, DWORD& section, DWORD& offset )
{
    MEMORY_BASIC_INFORMATION mbi;

    if ( !VirtualQuery( addr, &mbi, sizeof(mbi) ) )
        return FALSE;

    DWORD hMod = (DWORD)mbi.AllocationBase;

    if ( !GetModuleFileName( (HMODULE)hMod, szModule, len ) )
        return FALSE;

    // Point to the DOS header in memory
    PIMAGE_DOS_HEADER pDosHdr = (PIMAGE_DOS_HEADER)hMod;

    // From the DOS header, find the NT (PE) header
    PIMAGE_NT_HEADERS pNtHdr = (PIMAGE_NT_HEADERS)(hMod + pDosHdr->e_lfanew);

    PIMAGE_SECTION_HEADER pSection = IMAGE_FIRST_SECTION( pNtHdr );

    DWORD rva = (DWORD)addr - hMod; // RVA is offset from module load address

    // Iterate through the section table, looking for the one that encompasses
    // the linear address.
    for (   unsigned i = 0;
            i < pNtHdr->FileHeader.NumberOfSections;
            i++, pSection++ )
    {
        DWORD sectionStart = pSection->VirtualAddress;
        DWORD sectionEnd = sectionStart
                    + max(pSection->SizeOfRawData, pSection->Misc.VirtualSize);

        // Is the address in this section???
        if ( (rva >= sectionStart) && (rva <= sectionEnd) )
        {
            // Yes, address is in the section.  Calculate section and offset,
            // and store in the "section" & "offset" params, which were
            // passed by reference.
            section = i+1;
            offset = rva - sectionStart;
            return TRUE;
        }
    }

    return FALSE;   // Should never get here!
}

//============================================================
// Walks the stack, and writes the results to the report file 
//============================================================
//void WheatyExceptionReport::WriteStackDetails(
//        PCONTEXT pContext,
//        bool bWriteVariables )  // true if local/params should be output
//{
//    _tprintf( _T("\r\nCall stack:\r\n") );
//
//    _tprintf( _T("Address   Frame     Function            SourceFile\r\n") );
//
//    DWORD dwMachineType = 0;
//    // Could use SymSetOptions here to add the SYMOPT_DEFERRED_LOADS flag
//
//    STACKFRAME sf;
//    memset( &sf, 0, sizeof(sf) );
//
//    #ifdef _M_IX86
//    // Initialize the STACKFRAME structure for the first call.  This is only
//    // necessary for Intel CPUs, and isn't mentioned in the documentation.
//    sf.AddrPC.Offset       = pContext->Eip;
//    sf.AddrPC.Mode         = AddrModeFlat;
//    sf.AddrStack.Offset    = pContext->Esp;
//    sf.AddrStack.Mode      = AddrModeFlat;
//    sf.AddrFrame.Offset    = pContext->Ebp;
//    sf.AddrFrame.Mode      = AddrModeFlat;
//
//    dwMachineType = IMAGE_FILE_MACHINE_I386;
//    #endif
//
//    while ( 1 )
//    {
//        // Get the next stack frame
//        if ( ! StackWalk(  dwMachineType,
//                            m_hProcess,
//                            GetCurrentThread(),
//                            &sf,
//                            pContext,
//                            0,
//                            SymFunctionTableAccess,
//                            SymGetModuleBase,
//                            0 ) )
//            break;
//
//        if ( 0 == sf.AddrFrame.Offset ) // Basic sanity check to make sure
//            break;                      // the frame is OK.  Bail if not.
//
//        _tprintf( _T("%08X  %08X  "), sf.AddrPC.Offset, sf.AddrFrame.Offset );
//
//        // Get the name of the function for this stack frame entry
//        BYTE symbolBuffer[ sizeof(SYMBOL_INFO) + 1024 ];
//        PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)symbolBuffer;
//        pSymbol->SizeOfStruct = sizeof(symbolBuffer);
//        pSymbol->MaxNameLen = 1024;
//                        
//        DWORD64 symDisplacement = 0;    // Displacement of the input address,
//                                        // relative to the start of the symbol
//
//        if ( SymFromAddr(m_hProcess,sf.AddrPC.Offset,&symDisplacement,pSymbol))
//        {
//            _tprintf( _T("%hs+%I64X"), pSymbol->Name, symDisplacement );
//            
//        }
//        else    // No symbol found.  Print out the logical address instead.
//        {
//            TCHAR szModule[MAX_PATH] = _T("");
//            DWORD section = 0, offset = 0;
//
//            GetLogicalAddress(  (PVOID)sf.AddrPC.Offset,
//                                szModule, sizeof(szModule), section, offset );
//
//            _tprintf( _T("%04X:%08X %s"), section, offset, szModule );
//        }
//
//        // Get the source line for this stack frame entry
//        IMAGEHLP_LINE lineInfo = { sizeof(IMAGEHLP_LINE) };
//        DWORD dwLineDisplacement;
//        if ( SymGetLineFromAddr( m_hProcess, sf.AddrPC.Offset,
//                                &dwLineDisplacement, &lineInfo ) )
//        {
//            _tprintf(_T("  %s line %u"),lineInfo.FileName,lineInfo.LineNumber); 
//        }
//
//        _tprintf( _T("\r\n") );
//
//        // Write out the variables, if desired
//        if ( bWriteVariables )
//        {
//            // Use SymSetContext to get just the locals/params for this frame
//            IMAGEHLP_STACK_FRAME imagehlpStackFrame;
//            imagehlpStackFrame.InstructionOffset = sf.AddrPC.Offset;
//            SymSetContext( m_hProcess, &imagehlpStackFrame, 0 );
//
//            // Enumerate the locals/parameters
//            SymEnumSymbols( m_hProcess, 0, 0, EnumerateSymbolsCallback, &sf );
//
//            _tprintf( _T("\r\n") );
//        }
//    }
//
//}
void WheatyExceptionReport::WriteStackDetails(
	PCONTEXT pContext,
	bool bWriteVariables )  // true if local/params should be output
{
	Report( _T("\r\nCall stack:\r\n") );

	Report( _T("Address   Frame     Function            SourceFile\r\n") );

	DWORD dwMachineType = 0;
	// Could use SymSetOptions here to add the SYMOPT_DEFERRED_LOADS flag

	STACKFRAME sf;
	memset( &sf, 0, sizeof(sf) );

#ifdef _M_IX86
	// Initialize the STACKFRAME structure for the first call.  This is only
	// necessary for Intel CPUs, and isn't mentioned in the documentation.
	sf.AddrPC.Offset       = pContext->Eip;
	sf.AddrPC.Mode         = AddrModeFlat;
	sf.AddrStack.Offset    = pContext->Esp;
	sf.AddrStack.Mode      = AddrModeFlat;
	sf.AddrFrame.Offset    = pContext->Ebp;
	sf.AddrFrame.Mode      = AddrModeFlat;

	dwMachineType = IMAGE_FILE_MACHINE_I386;
#endif

	while ( 1 )
	{
		// Get the next stack frame
		if ( ! StackWalk(  dwMachineType,
			m_hProcess,
			GetCurrentThread(),
			&sf,
			pContext,
			0,
			SymFunctionTableAccess,
			SymGetModuleBase,
			0 ) )
			break;

		if ( 0 == sf.AddrFrame.Offset ) // Basic sanity check to make sure
			break;                      // the frame is OK.  Bail if not.

		Report( _T("%08X  %08X  "), sf.AddrPC.Offset, sf.AddrFrame.Offset );

		// Get the name of the function for this stack frame entry
		BYTE symbolBuffer[ sizeof(SYMBOL_INFO) + 1024 ];
		PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)symbolBuffer;
		pSymbol->SizeOfStruct = sizeof(symbolBuffer);
		pSymbol->MaxNameLen = 1024;

		DWORD64 symDisplacement = 0;    // Displacement of the input address,
		// relative to the start of the symbol

		if ( SymFromAddr(m_hProcess,sf.AddrPC.Offset,&symDisplacement,pSymbol))
		{
			Report( _T("%hs+%I64X"), pSymbol->Name, symDisplacement );

		}
		else    // No symbol found.  Print out the logical address instead.
		{
			TCHAR szModule[MAX_PATH] = _T("");
			DWORD section = 0, offset = 0;

			GetLogicalAddress(  (PVOID)sf.AddrPC.Offset,
				szModule, sizeof(szModule), section, offset );

			Report( _T("%04X:%08X %s"), section, offset, szModule );
		}

		// Get the source line for this stack frame entry
		IMAGEHLP_LINE lineInfo = { sizeof(IMAGEHLP_LINE) };
		DWORD dwLineDisplacement;
		if ( SymGetLineFromAddr( m_hProcess, sf.AddrPC.Offset,
			&dwLineDisplacement, &lineInfo ) )
		{
			Report(_T("  %s line %u"),lineInfo.FileName,lineInfo.LineNumber); 
		}

		Report( _T("\r\n") );

		// Write out the variables, if desired
		if ( bWriteVariables )
		{
			// Use SymSetContext to get just the locals/params for this frame
			IMAGEHLP_STACK_FRAME imagehlpStackFrame;
			imagehlpStackFrame.InstructionOffset = sf.AddrPC.Offset;
			SymSetContext( m_hProcess, &imagehlpStackFrame, 0 );

			// Enumerate the locals/parameters
			SymEnumSymbols( m_hProcess, 0, 0, EnumerateSymbolsCallback, &sf );

			Report( _T("\r\n") );
		}
	}

}
//////////////////////////////////////////////////////////////////////////////
// The function invoked by SymEnumSymbols
//////////////////////////////////////////////////////////////////////////////

BOOL CALLBACK
WheatyExceptionReport::EnumerateSymbolsCallback(
    PSYMBOL_INFO  pSymInfo,
    ULONG         SymbolSize,
    PVOID         UserContext )
{

    char szBuffer[2048];

    __try
    {
        if ( FormatSymbolValue( pSymInfo, (STACKFRAME*)UserContext,
                                szBuffer, sizeof(szBuffer) ) )  
            _tprintf( _T("\t%s\r\n"), szBuffer );
    }
    __except( 1 )
    {
        _tprintf( _T("punting on symbol %s\r\n"), pSymInfo->Name );
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// Given a SYMBOL_INFO representing a particular variable, displays its
// contents.  If it's a user defined type, display the members and their
// values.
//////////////////////////////////////////////////////////////////////////////
bool WheatyExceptionReport::FormatSymbolValue(
            PSYMBOL_INFO pSym,
            STACKFRAME * sf,
            char * pszBuffer,
            unsigned cbBuffer )
{
    char * pszCurrBuffer = pszBuffer;

    // Indicate if the variable is a local or parameter
    if ( pSym->Flags & IMAGEHLP_SYMBOL_INFO_PARAMETER )
        pszCurrBuffer += sprintf( pszCurrBuffer, "Parameter " );
    else if ( pSym->Flags & IMAGEHLP_SYMBOL_INFO_LOCAL )
        pszCurrBuffer += sprintf( pszCurrBuffer, "Local " );

    // If it's a function, don't do anything.
    if ( pSym->Tag == 5 )   // SymTagFunction from CVCONST.H from the DIA SDK
        return false;

    // Emit the variable name
    pszCurrBuffer += sprintf( pszCurrBuffer, "\'%s\'", pSym->Name );

    DWORD_PTR pVariable = 0;    // Will point to the variable's data in memory

    if ( pSym->Flags & IMAGEHLP_SYMBOL_INFO_REGRELATIVE )
    {
        // if ( pSym->Register == 8 )   // EBP is the value 8 (in DBGHELP 5.1)
        {                               //  This may change!!!
            pVariable = sf->AddrFrame.Offset;
            pVariable += (DWORD_PTR)pSym->Address;
        }
        // else
        //  return false;
    }
    else if ( pSym->Flags & IMAGEHLP_SYMBOL_INFO_REGISTER )
    {
        return false;   // Don't try to report register variable
    }
    else
    {
        pVariable = (DWORD_PTR)pSym->Address;   // It must be a global variable
    }

    // Determine if the variable is a user defined type (UDT).  IF so, bHandled
    // will return true.
    bool bHandled;
    pszCurrBuffer = DumpTypeIndex(pszCurrBuffer,pSym->ModBase, pSym->TypeIndex,
                                    0, pVariable, bHandled );

    if ( !bHandled )
    {
        // The symbol wasn't a UDT, so do basic, stupid formatting of the
        // variable.  Based on the size, we're assuming it's a char, WORD, or
        // DWORD.
        BasicType basicType = GetBasicType( pSym->TypeIndex, pSym->ModBase );
        
        pszCurrBuffer = FormatOutputValue(pszCurrBuffer, basicType, pSym->Size,
                                            (PVOID)pVariable ); 
    }


    return true;
}

//////////////////////////////////////////////////////////////////////////////
// If it's a user defined type (UDT), recurse through its members until we're
// at fundamental types.  When he hit fundamental types, return
// bHandled = false, so that FormatSymbolValue() will format them.
//////////////////////////////////////////////////////////////////////////////
char * WheatyExceptionReport::DumpTypeIndex(
        char * pszCurrBuffer,
        DWORD64 modBase,
        DWORD dwTypeIndex,
        unsigned nestingLevel,
        DWORD_PTR offset,
        bool & bHandled )
{
    bHandled = false;

    // Get the name of the symbol.  This will either be a Type name (if a UDT),
    // or the structure member name.
    WCHAR * pwszTypeName;
    if ( SymGetTypeInfo( m_hProcess, modBase, dwTypeIndex, TI_GET_SYMNAME,
                        &pwszTypeName ) )
    {
        pszCurrBuffer += sprintf( pszCurrBuffer, " %ls", pwszTypeName );
        LocalFree( pwszTypeName );
    }

    // Determine how many children this type has.
    DWORD dwChildrenCount = 0;
    SymGetTypeInfo( m_hProcess, modBase, dwTypeIndex, TI_GET_CHILDRENCOUNT,
                    &dwChildrenCount );

    if ( !dwChildrenCount )     // If no children, we're done
        return pszCurrBuffer;

    // Prepare to get an array of "TypeIds", representing each of the children.
    // SymGetTypeInfo(TI_FINDCHILDREN) expects more memory than just a
    // TI_FINDCHILDREN_PARAMS struct has.  Use derivation to accomplish this.
    struct FINDCHILDREN : TI_FINDCHILDREN_PARAMS
    {
        ULONG   MoreChildIds[1024];
        FINDCHILDREN(){Count = sizeof(MoreChildIds) / sizeof(MoreChildIds[0]);}
    } children;

    children.Count = dwChildrenCount;
    children.Start= 0;

    // Get the array of TypeIds, one for each child type
    if ( !SymGetTypeInfo( m_hProcess, modBase, dwTypeIndex, TI_FINDCHILDREN,
                            &children ) )
    {
        return pszCurrBuffer;
    }

    // Append a line feed
    pszCurrBuffer += sprintf( pszCurrBuffer, "\r\n" );

    // Iterate through each of the children
    for ( unsigned i = 0; i < dwChildrenCount; i++ )
    {
        // Add appropriate indentation level (since this routine is recursive)
        for ( unsigned j = 0; j <= nestingLevel+1; j++ )
            pszCurrBuffer += sprintf( pszCurrBuffer, "\t" );

        // Recurse for each of the child types
        bool bHandled2;
        pszCurrBuffer = DumpTypeIndex( pszCurrBuffer, modBase,
                                        children.ChildId[i], nestingLevel+1,
                                        offset, bHandled2 );

        // If the child wasn't a UDT, format it appropriately
        if ( !bHandled2 )
        {
            // Get the offset of the child member, relative to its parent
            DWORD dwMemberOffset;
            SymGetTypeInfo( m_hProcess, modBase, children.ChildId[i],
                            TI_GET_OFFSET, &dwMemberOffset );

            // Get the real "TypeId" of the child.  We need this for the
            // SymGetTypeInfo( TI_GET_TYPEID ) call below.
            DWORD typeId;
            SymGetTypeInfo( m_hProcess, modBase, children.ChildId[i],
                            TI_GET_TYPEID, &typeId );

            // Get the size of the child member
            ULONG64 length;
            SymGetTypeInfo(m_hProcess, modBase, typeId, TI_GET_LENGTH,&length);

            // Calculate the address of the member
            DWORD_PTR dwFinalOffset = offset + dwMemberOffset;

            BasicType basicType = GetBasicType(children.ChildId[i], modBase );

            pszCurrBuffer = FormatOutputValue( pszCurrBuffer, basicType,
                                                length, (PVOID)dwFinalOffset ); 

            pszCurrBuffer += sprintf( pszCurrBuffer, "\r\n" );
        }
    }

    bHandled = true;
    return pszCurrBuffer;
}

char * WheatyExceptionReport::FormatOutputValue(   char * pszCurrBuffer,
                                                    BasicType basicType,
                                                    DWORD64 length,
                                                    PVOID pAddress )
{
    // Format appropriately (assuming it's a 1, 2, or 4 bytes (!!!)
    if ( length == 1 )
        pszCurrBuffer += sprintf( pszCurrBuffer, " = %X", *(PBYTE)pAddress );
    else if ( length == 2 )
        pszCurrBuffer += sprintf( pszCurrBuffer, " = %X", *(PWORD)pAddress );
    else if ( length == 4 )
    {
        if ( basicType == btFloat )
        {
            pszCurrBuffer += sprintf(pszCurrBuffer," = %f", *(PFLOAT)pAddress);
        }
        else if ( basicType == btChar )
        {
            if ( !IsBadStringPtr( *(PSTR*)pAddress, 32) )
            {
                pszCurrBuffer += sprintf( pszCurrBuffer, " = \"%.31s\"",
                                            *(PDWORD)pAddress );
            }
            else
                pszCurrBuffer += sprintf( pszCurrBuffer, " = %X",
                                            *(PDWORD)pAddress );
        }
        else
            pszCurrBuffer += sprintf(pszCurrBuffer," = %X", *(PDWORD)pAddress);
    }
    else if ( length == 8 )
    {
        if ( basicType == btFloat )
        {
            pszCurrBuffer += sprintf( pszCurrBuffer, " = %lf",
                                        *(double *)pAddress );
        }
        else
            pszCurrBuffer += sprintf( pszCurrBuffer, " = %I64X",
                                        *(DWORD64*)pAddress );
    }

    return pszCurrBuffer;
}

BasicType
WheatyExceptionReport::GetBasicType( DWORD typeIndex, DWORD64 modBase )
{
    BasicType basicType;
    if ( SymGetTypeInfo( m_hProcess, modBase, typeIndex,
                        TI_GET_BASETYPE, &basicType ) )
    {
        return basicType;
    }

    // Get the real "TypeId" of the child.  We need this for the
    // SymGetTypeInfo( TI_GET_TYPEID ) call below.
    DWORD typeId;
    if (SymGetTypeInfo(m_hProcess,modBase, typeIndex, TI_GET_TYPEID, &typeId))
    {
        if ( SymGetTypeInfo( m_hProcess, modBase, typeId, TI_GET_BASETYPE,
                            &basicType ) )
        {
            return basicType;
        }
    }

    return btNoType;
}

//============================================================================
// Helper function that writes to the report file, and allows the user to use 
// printf style formating                                                     
//============================================================================
int __cdecl WheatyExceptionReport::_tprintf(const TCHAR * format, ...)
{
    TCHAR szBuff[1024];
    int retValue;
    DWORD cbWritten;
    va_list argptr;
          
    va_start( argptr, format );
    retValue = vsprintf( szBuff, format, argptr );
    va_end( argptr );

    WriteFile(m_hReportFile, szBuff, retValue * sizeof(TCHAR), &cbWritten, 0 );

    return retValue;
}

//============================================================================
// RealRender added 2004.09.26
// 
//============================================================================
CExceptionAddressToSrcLine::CExceptionAddressToSrcLine(void):
m_dwNearestSrcAddr(0),
m_dwNearestSrcLine(0)
{
	m_szSrcFileDesc[0] = 0;
	m_szMapFilename[0] = 0;
}

CExceptionAddressToSrcLine::~CExceptionAddressToSrcLine(void)
{
}

void CExceptionAddressToSrcLine::SetMapFilename( const char* pszMapFilename )
{
    if ( pszMapFilename == NULL || *pszMapFilename == 0 )
    { return; }

	strncpy_s(m_szMapFilename, sizeof(m_szMapFilename), pszMapFilename, sizeof(m_szMapFilename)-1);
}

BOOL CExceptionAddressToSrcLine::IsMapFileExist()
{
	FILE* fp = fopen( m_szMapFilename, "r" );
	if( !fp )
		return FALSE;
	fclose( fp );
	return TRUE;
}

BOOL CExceptionAddressToSrcLine::Exception( DWORD dwExceptAddr )
{
	if( !IsMapFileExist() )
		return FALSE;
	return AddrToSrcLine( m_szMapFilename, dwExceptAddr );
}

DWORD CExceptionAddressToSrcLine::HexToDec( const char* pszNumber )
{
	DWORD dwNumber = 0;
	const char* p = pszNumber;
	while( *p )
	{
		dwNumber *= 16;
		switch( *p )
		{
		case '0':
			dwNumber += 0;
			break;
		case '1':
			dwNumber += 1;
			break;
		case '2':
			dwNumber += 2;
			break;
		case '3':
			dwNumber += 3;
			break;
		case '4':
			dwNumber += 4;
			break;
		case '5':
			dwNumber += 5;
			break;
		case '6':
			dwNumber += 6;
			break;
		case '7':
			dwNumber += 7;
			break;
		case '8':
			dwNumber += 8;
			break;
		case '9':
			dwNumber += 9;
			break;
		case 'a':
		case 'A':
			dwNumber += 10;
			break;
		case 'b':
		case 'B':
			dwNumber += 11;
			break;
		case 'c':
		case 'C':
			dwNumber += 12;
			break;
		case 'd':
		case 'D':
			dwNumber += 13;
			break;
		case 'e':
		case 'E':
			dwNumber += 14;
			break;
		case 'f':
		case 'F':
			dwNumber += 15;
			break;
		}
		p++;
	}
	return dwNumber;
}

BOOL CExceptionAddressToSrcLine::AddrToSrcLine( const char* pszMapFilename, DWORD dwExceptAddr )
{
	FILE* fp = fopen( pszMapFilename, "r" );
	if( !fp )
		return FALSE;

	// ������ƫ�� = ������ַ��Crash Address�� - ����ַ��ImageBase Address�� - 0x1000
	dwExceptAddr -= 0x00400000;
	dwExceptAddr -= 0x1000;
	
	char s[4096];

	BOOL	bLineStart = FALSE;
	char szCurSrcFilename[1024];
	
	int nLine = 0;
	size_t nLineStartStrinLen = strlen( "Line numbers" );
	while( fgets( s, 4096, fp) )
	{
		nLine++;
		size_t nLen = strlen( s );
		if( nLen == 0 )
			continue;
		if( s[nLen-1] == '\n' )
		{
			s[nLen-1] = 0;
			nLen--;
		}

		if( strnicmp( s, "Line numbers", nLineStartStrinLen ) == 0 )
		{
			if( !bLineStart )
				bLineStart = TRUE;
			strncpy_s(szCurSrcFilename, sizeof(szCurSrcFilename), s, sizeof(szCurSrcFilename)-1);
			continue;	
		}
		if( !bLineStart )
			continue;
		
		size_t nRecordCount = nLen/20;
		for( size_t i = 0; i < nRecordCount; i++)
		{
			DWORD dwSrcLine;
			char szAddr[1024];
			sscanf( &s[i*20], "%ld %s", &dwSrcLine, szAddr );
			char* pszAddr = &szAddr[5];
			DWORD dwAddr = HexToDec( pszAddr );


			DWORD dwMin = dwExceptAddr-m_dwNearestSrcAddr;
			// �����ǰ��ַС���쳣��ַ����ƫ������֮ǰ�ҵ��ĸ�С
			if( dwAddr <= dwExceptAddr &&
				dwExceptAddr-dwAddr < dwMin )
			{
				m_dwNearestSrcAddr = dwAddr;
				m_dwNearestSrcLine = dwSrcLine;
				strncpy_s(m_szSrcFileDesc, sizeof(m_szSrcFileDesc), szCurSrcFilename, sizeof(m_szSrcFileDesc)-1);
			}
		}

		
	}
	fclose( fp );

	
	char szSrcFilename[1024];
	strncpy_s(szSrcFilename, sizeof(szSrcFilename), m_szSrcFileDesc, sizeof(szSrcFilename)-1);
	size_t nLen = strlen( szSrcFilename );
	for( size_t i = 0; i < nLen; i++ )
	{
		if( szSrcFilename[i] == '(' )
		{
			strncpy_s(m_szSrcFileDesc, sizeof(m_szSrcFileDesc), &szSrcFilename[i+1], sizeof(m_szSrcFileDesc)-1);
		}
	}
	nLen = strlen( m_szSrcFileDesc );
	for( size_t i = 0; i < nLen; i++ )
	{
		if( m_szSrcFileDesc[i] == ')' )
			m_szSrcFileDesc[i] = 0;
	}
	
	
	return TRUE;
}

#pragma warning ( pop )