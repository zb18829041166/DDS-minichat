
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from minichat.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef minichat_1974240433_h
#define minichat_1974240433_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif


#define MiniChat_LAST_MEMBER_ID 0
#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *MiniChatTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct MiniChatSeq;

#ifndef NDDS_STANDALONE_TYPE
    class MiniChatTypeSupport;
    class MiniChatDataWriter;
    class MiniChatDataReader;
#endif

#endif

            
    
class MiniChat                                        
{
public:            
#ifdef __cplusplus
    typedef struct MiniChatSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef MiniChatTypeSupport TypeSupport;
    typedef MiniChatDataWriter DataWriter;
    typedef MiniChatDataReader DataReader;
#endif

#endif
    
    char*  MiniChat; /* maximum length = (32) */

            
};                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* MiniChat_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(MiniChatSeq, MiniChat);
        
NDDSUSERDllExport
RTIBool MiniChat_initialize(
        MiniChat* self);
        
NDDSUSERDllExport
RTIBool MiniChat_initialize_ex(
        MiniChat* self,
        RTIBool allocatePointers,RTIBool allocateMemory);
        
NDDSUSERDllExport
RTIBool MiniChat_initialize_w_params(
        MiniChat* self,
        const struct DDS_TypeAllocationParams_t * allocParams);

NDDSUSERDllExport
void MiniChat_finalize(
        MiniChat* self);
                        
NDDSUSERDllExport
void MiniChat_finalize_ex(
        MiniChat* self,RTIBool deletePointers);
       
NDDSUSERDllExport
void MiniChat_finalize_w_params(
        MiniChat* self,
        const struct DDS_TypeDeallocationParams_t * deallocParams);
        
NDDSUSERDllExport
void MiniChat_finalize_optional_members(
        MiniChat* self, RTIBool deletePointers);        
        
NDDSUSERDllExport
RTIBool MiniChat_copy(
        MiniChat* dst,
        const MiniChat* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* minichat_1974240433_h */
