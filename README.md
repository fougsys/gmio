<img src="doc/gmio.png" height="91" alt="gmio_logo"/>
======================================================

[![Build Status](https://travis-ci.org/fougue/gmio.svg?branch=master)](https://travis-ci.org/fougue/gmio) 
[![Build status](https://ci.appveyor.com/api/projects/status/0q4f69lqo6sw9108?svg=true)](https://ci.appveyor.com/project/HuguesDelorme/gmio) 
<a href="https://scan.coverity.com/projects/5721">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/5721/badge.svg"/>
</a>
[![Coverage Status](https://coveralls.io/repos/fougue/gmio/badge.svg?branch=master&service=github)](https://coveralls.io/github/fougue/gmio?branch=master) 
[![License](https://img.shields.io/badge/license-CeCILL--B-blue.svg)](http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html)  


C library for geometry input/output
===========================================

gmio is a reusable C library whose purpose is to provide complete I/O
support for various CAD file formats (eg. [STL](https://en.wikipedia.org/wiki/STL_%28file_format%29))

gmio aims to be [fast](https://github.com/fougue/gmio/wiki/4.-Benchmarks),
portable (C90 conformance) and feature-rich.

Main highlights:

  * [x] "Abstract" streams that does not tie the user to C stream(`FILE*`)
  * [x] Buffering of input/ouput for efficient device usage
  * [x] Operations can be easily aborted
  * [x] Progress report about the I/O operation
  * [x] Available under the CeCILL-B license, which is fully BSD compatible


Supported CAD files format
==========================

Current version only supports the STL file format (STereoLithography), but
support is complete :

  * [x] ASCII format: Case-insensitive reading
  * [x] ASCII format: Output format(%f, %e, ...) and precision of floats support
  * [x] Binary format: Little/big endian support
  * [x] Binary format: 80-byte header and facet "attribute byte count" support
  * [x] Detection of the input format
  * [x] Retrieval of infomations about contents(facet count, solid name, ...)
  * [x] Multiple solids from stream(eg. 4 solids in STL ascii file)

In addition, the STL module has the following advatanges:

  * [x] The user keeps its own geometry data structures, no mesh conversion needed
  * [x] Fixed memory consumption and independant of the mesh size
  * [x] Seamless use of [OpenCascade StlMesh_Mesh](http://dev.opencascade.org/doc/refman/html/class_stl_mesh___mesh.html)
        in gmio(see gmio_support)


Building gmio
===============

gmio can be built with CMake, by default a static library is generated.

Read the [Build instructions](https://github.com/fougue/gmio/wiki/2.-Build-instructions)



How to report a bug
===================

The gmio bug tracking system is open to the public at
https://github.com/fougue/gmio/issues.

If you think you have found a bug in gmio, we would like to hear
about it so that we can fix it.

Always include the following information in your bug report:
  * the name and version number of your compiler
  * the name and version number of your operating system
  * the version of gmio you are using
  * what configure options it was compiled with.

If the problem you are reporting is only visible at run-time, try to
create a small test program that shows the problem when run.


License
=======

This software is governed by the CeCILL-B license under French law and
abiding by the rules of distribution of free software.

You can  use, modify and/ or redistribute the software under the terms of the
[CeCILL-B license](http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html)
as circulated by CEA, CNRS and INRIA


Credits
=======

"gmio" logo rendered with Prism font (thanks to Erik Yin !)
