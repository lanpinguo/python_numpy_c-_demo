#!/usr/bin/env python 
from distutils.core import setup 
from distutils.extension import Extension 
  
setup(name = 'max30102',
    version = '0.5',
    license = 'GNU GPL v2',
    description = 'max30102 algorithm debug',
 ext_modules=[ 
  Extension("max30102", ["main.cpp","objs/algorithm.cpp"], 
  libraries = ["boost_python","boost_numpy"],
  include_dirs = ['./objs'] 
  ),
 ]
)
