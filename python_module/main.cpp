#include <boost/python.hpp> 
#include <boost/python/numpy.hpp>
#include "algorithm.h"



namespace bpy = boost::python;
namespace np = boost::python::numpy;

boost::python::list Square(boost::python::list& data) 
{ 
 boost::python::list ret; 
 for (int i = 0; i < len(data); ++i) 
 { 
  ret.append(data[i] * data[i]); 
 } 
  
 return ret; 
} 

int test_change(double* in, double* out, int n)
{
	for(int i = 0; i < n ; i++){
		out[i] = in[i]*in[i]*2 + 1;
	}

}



np::ndarray do_stuff(const np::ndarray& input_array) {
		char *data =  input_array.get_data();
		int total_byts = 0;
		int nd = input_array.get_nd();


		
		printf("\r\nnd = %d",nd);
		printf("\r\nData:\r\n");
		for(int i = 0; i < nd; i++){
			printf("\r\nstrides[%d] = %d",i,input_array.strides(i));
			printf("\r\nshape[%d] = %d",i,input_array.shape(i));
			total_byts += input_array.strides(i) * input_array.shape(i);
		}
		for(int i = 0 ; i < total_byts; i ++ )
		{
			if(i % 16 == 0){
				printf("\r\n%04d : ",i);
			}
			printf("%02x ",data[i]);
		}
		printf("\r\n");

	  Py_intptr_t shape[1] = { input_array.shape(0) };
    np::ndarray result = np::zeros(1, shape, np::dtype::get_builtin<double>());
		test_change(reinterpret_cast<double*>(input_array.get_data()),
								reinterpret_cast<double*>(result.get_data()),
								input_array.shape(0));


    return result;
		
};


BOOST_PYTHON_MODULE(max30102) 
{ 	
	np::initialize();
	def("Square", Square); 
	boost::python::def("test", do_stuff);
}
