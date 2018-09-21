
#include "sdp.h"
#include "debug.h"
#include "mat.h"
namespace nvdla {

DEFINE_LAYER_CREATOR(NvdlaSDP)

NvdlaSDP::NvdlaSDP()
{
    src_mem_flag = -1;
    weight_mem_flag = -1;
    dst_mem_flag = -1;
    nvdla_type = NvSDP;
    action = ACTION_NONE;
    set_bpe(2);
}
NvdlaSDP::~NvdlaSDP()
{
}

void NvdlaSDP::set_weight_data(Mat weight_data_p)
{
    weight_data = weight_data_p;
}




void NvdlaSDP::print_layer_info(void)
{

    debug_info("sdp info.........\n");
    debug_info("para...\n");
    debug_info("layer_type=%d,slope=%d \n",nvdla_type,slope);
    debug_info("src_mem_flag=%d,weight_mem_flag=%d,dst_mem_flag=%d\n",src_mem_flag,weight_mem_flag,dst_mem_flag);
    #if 0
    debug_info("weight data top 10...\n");
    float *data = (float *)weight_data.data;
    for(int i =0; i < 10; i++)
    {
        debug_info("index=%d,data=%f\n",i,data++);
    }
    #endif 
    
    #if 0
    debug_info("weight data tail 10...\n");
    data = (float *)weight_data.data;
    for(int i=weight_data_size-10; i< weight_data_size; i++)
    {
        debug_info("index=%d,data=%f\n",i,data[i]);
    }
    #endif

}

union dla_layer_param_container NvdlaSDP::get_params(void)
{

    union dla_layer_param_container params;
    params.sdp_params.slope = slope;
    return params;
}

void NvdlaSDP::set_action(dla_action action_p)
{
    action = action_p;
}

dla_action NvdlaSDP::get_action(void)
{
    return action;
}


} 





