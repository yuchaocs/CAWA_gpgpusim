#!/bin/bash

config()
{
    cd ${1}/configs/GTX480
    if [ ! -f gpgpusim.config.${2} ]
    then
	echo "your scheduling policy not supported, or use small letters"
	exit 1
    fi

    cp gpgpusim.config.${2} gpgpusim.config
    if [ "$3" = "no" ]
    then
	printf "\n-gpgpu_load_oracle_counter 1" >> gpgpusim.config
    else
	printf "\n-gpgpu_store_oracle_counter 1" >> gpgpusim.config
    fi
    if [ "$4" = "yes" ]
    then
	printf "\n-gpgpu_with_cacp 1" >> gpgpusim.config
    fi
    cd ../../../
}