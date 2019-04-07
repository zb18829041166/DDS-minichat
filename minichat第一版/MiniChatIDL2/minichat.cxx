
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from minichat.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/


#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
        #ifndef dds_c_log_impl_h              
            #include "dds_c/dds_c_log_impl.h"                                
        #endif        
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
    
    #ifndef cdr_type_h
        #include "cdr/cdr_type.h"
    #endif    

    #ifndef osapi_heap_h
        #include "osapi/osapi_heap.h" 
    #endif
#else
    #include "ndds_standalone_type.h"
#endif



#include "minichat.h"

/* ========================================================================= */
const char *MiniChatTYPENAME = "MiniChat";

DDS_TypeCode* MiniChat_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode MiniChat_g_tc_MiniChat_string = DDS_INITIALIZE_STRING_TYPECODE(32);

    static DDS_TypeCode_Member MiniChat_g_tc_members[1]=
    {
        {
            (char *)"MiniChat",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Member flags */
            DDS_PRIVATE_MEMBER,/* Ignored */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode MiniChat_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MiniChat", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        MiniChat_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for MiniChat*/

    if (is_initialized) {
        return &MiniChat_g_tc;
    }


    MiniChat_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&MiniChat_g_tc_MiniChat_string;

    is_initialized = RTI_TRUE;

    return &MiniChat_g_tc;
}


RTIBool MiniChat_initialize(
    MiniChat* sample) {
  return MiniChat_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool MiniChat_initialize_ex(
    MiniChat* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
    struct DDS_TypeAllocationParams_t allocParams =
        DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;
        
    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;
    
    return MiniChat_initialize_w_params(
        sample,&allocParams);
}

RTIBool MiniChat_initialize_w_params(
        MiniChat* sample,
        const struct DDS_TypeAllocationParams_t * allocParams)
{
        
    
    if (allocParams) {} /* To avoid warnings */
        

    if (allocParams->allocate_memory) {
        sample->MiniChat = DDS_String_alloc((32));
        if (sample->MiniChat == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->MiniChat != NULL) { 
            sample->MiniChat[0] = '\0';
        }
    }
            


    return RTI_TRUE;
}

void MiniChat_finalize(
    MiniChat* sample)
{
    MiniChat_finalize_ex(sample,RTI_TRUE);
}
        
void MiniChat_finalize_ex(
    MiniChat* sample,RTIBool deletePointers)
{        
    struct DDS_TypeDeallocationParams_t deallocParams =
            DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample) { } /* To avoid warnings */
    
    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    MiniChat_finalize_w_params(
        sample,&deallocParams);
}

void MiniChat_finalize_w_params(
        MiniChat* sample,
        const struct DDS_TypeDeallocationParams_t * deallocParams)
{    
    if (sample) { } /* To avoid warnings */
    if (deallocParams) {} /* To avoid warnings */


    if (sample->MiniChat != NULL) {    
        DDS_String_free(sample->MiniChat);
        sample->MiniChat = NULL;
    }
            

}

void MiniChat_finalize_optional_members(
    MiniChat* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
        DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
        &deallocParamsTmp;
    if (sample) { } /* To avoid warnings */
    if (deallocParams) {} /* To avoid warnings */

        

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;    
             


}

RTIBool MiniChat_copy(
    MiniChat* dst,
    const MiniChat* src)
{

    if (!RTICdrType_copyString(
        dst->MiniChat, src->MiniChat, (32) + 1)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'MiniChat' sequence class.
 */
#define T MiniChat
#define TSeq MiniChatSeq
#define T_initialize_w_params MiniChat_initialize_w_params
#define T_finalize_w_params   MiniChat_finalize_w_params
#define T_copy       MiniChat_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

