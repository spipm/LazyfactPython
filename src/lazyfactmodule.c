// https://docs.python.org/2/extending/extending.html#providing-a-c-api-for-an-extension-module


#include <Python.h>

#include <lazyfactInclude/meth.h>
#include <stdio.h>
#include <gmp.h>

mpz_t n;
int status;


static PyObject *lazyfactError;

static PyObject *lazyfact_factor(PyObject *self, PyObject *args)
{
    Py_BEGIN_ALLOW_THREADS  // allow threading
    
    const char *modulus;
    int status;

    // get modulus as a string
    if (!PyArg_ParseTuple(args, "s", &modulus))
        return NULL;

    // load modulus into variable
    status = mpz_init_set_str(n, modulus, 10);
    if (status == FAIL) {
        PyErr_SetString(lazyfactError, "Factoring failed");
        return NULL;
    }
    // initialize factoring
    status = initLazyFact(&n);

    Py_END_ALLOW_THREADS    // stop threading and return value
    return Py_BuildValue("i", status);


}

static PyMethodDef lazyfactMethods[] = {
    {"factor",  lazyfact_factor, METH_VARARGS,
     "Factorises a RSA modulus."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC initlazyfact(void)
{
    PyObject *m;

    m = Py_InitModule("lazyfact", lazyfactMethods);
    if (m == NULL)
        return;

    lazyfactError = PyErr_NewException("lazyfact.error", NULL, NULL);
    Py_INCREF(lazyfactError);
    PyModule_AddObject(m, "error", lazyfactError);
}


int main(int argc, char *argv[])
{
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter.  Required. */
    Py_Initialize();

    /* Add a static module */
    initlazyfact();
    
    return 0;
}
