# https://docs.python.org/2/extending/building.html#building
# https://docs.python.org/2/distutils/apiref.html#distutils.core.setup

from distutils.core import setup, Extension

modulelazyfact = Extension('lazyfact',
    include_dirs=['.'],
    libraries = ['gmp', 'crypto'],
    sources = ['lazyfactmodule.c',
        			'init.c',
        			'printing.c',
        			'methodTrialDiv.c',
        			'methodPollardsRho.c',
        			'methodShankSquares.c',
        			'methodOpenSSLGen.c'])

setup (name = 'LazyFact',
       version = '1.0',
       description = 'Factoring RSA moduli using simple methods',
       author = 'Graa',
       url = 'https://github.com/DutchGraa',
       license = 'Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License',
       ext_modules = [modulelazyfact])
