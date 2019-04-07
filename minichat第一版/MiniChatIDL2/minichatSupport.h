
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from minichat.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef minichatSupport_1974240432_h
#define minichatSupport_1974240432_h

/* Uses */
#include "minichat.h"



#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

        

/* ========================================================================= */
/**
   Uses:     T

   Defines:  TTypeSupport, TDataWriter, TDataReader

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
  */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus

DDS_TYPESUPPORT_CPP(MiniChatTypeSupport, MiniChat);

DDS_DATAWRITER_CPP(MiniChatDataWriter, MiniChat);
DDS_DATAREADER_CPP(MiniChatDataReader, MiniChatSeq, MiniChat);


#else

DDS_TYPESUPPORT_C(MiniChatTypeSupport, MiniChat);
DDS_DATAWRITER_C(MiniChatDataWriter, MiniChat);
DDS_DATAREADER_C(MiniChatDataReader, MiniChatSeq, MiniChat);

#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif  /* minichatSupport_1974240432_h */
