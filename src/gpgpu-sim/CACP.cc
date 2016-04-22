/*********************************************************
 ****  Code for CACP			              ****
 ****  Contributed by David Joshy                     ****
 ****  Changes made in:                               ****
 ****     gpu-cache.cc                                ****
 ****     shader.cc                                   ****
 ****     gpu-cache.h                                 ****
 ****     shader.h 				      ****
 ****  04/07/16                                       ****
 *********************************************************/
#include "shader.h"

//***************** class shader_core_ctx *********************/
 void shader_core_ctx:: calc_warp_criticality_oracle()
 {
	 int max=0;
	 //need to add check for first run.
	 for (long index=0; index<(long)m_warp.size(); ++index) 
		if(max<m_warp.at(index).tw_get_oracle_CPL())
			max=m_warp.at(index).tw_cpl_oracle;
	 for (long index=0; index<(long)m_warp.size(); ++index) 
		if(m_warp.at(index).tw_get_oracle_CPL()/max>0.75)
				m_warp.at(index).criticality=1;
	 
	 
 }

void shader_core_ctx:: calc_warp_criticality_actual()
 {
	 float max=0;
	 //need to add check for first run.
	 for (long index=0; index<(long)m_warp.size(); ++index) 
		if(max<m_warp.at(index).tw_get_actual_CPL())
			max=m_warp.at(index).tw_cpl_oracle;
	 for (long index=0; index<(long)m_warp.size(); ++index) 
		if(m_warp.at(index).tw_get_actual_CPL()/max>0.75)
				m_warp.at(index).criticality=1;
	 
	 
 }
