/****************************************************************************
** gmio
** Copyright Fougue (2 Mar. 2015)
** contact@fougsys.fr
**
** This software is a reusable library whose purpose is to provide complete
** I/O support for various CAD file formats (eg. STL)
**
** This software is governed by the CeCILL-B license under French law and
** abiding by the rules of distribution of free software.  You can  use,
** modify and/ or redistribute the software under the terms of the CeCILL-B
** license as circulated by CEA, CNRS and INRIA at the following URL
** "http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html".
****************************************************************************/

/*! \file error.h
 *  List of common errors, reported by I/O functions
 */

#ifndef GMIO_ERROR_H
#define GMIO_ERROR_H

#include "global.h"

/*! This enum defines common errors */
enum gmio_error
{
    /*! No error occurred, success */
    GMIO_ERROR_OK = 0,

    /*! Pointer on argument gmio_transfer_t is NULL */
    GMIO_ERROR_NULL_TRANSFER,

    /*! Pointer on argument buffer is NULL */
    GMIO_ERROR_NULL_BUFFER,

    /*! Argument buffer's size is too small */
    GMIO_ERROR_INVALID_BUFFER_SIZE,

    /*! An error occurred with gmio_stream */
    GMIO_ERROR_STREAM,

    /*! Transfer was stopped by user, that is to say
     *  gmio_transfer::is_stop_requested_func() returned GMIO_TRUE */
    GMIO_ERROR_TRANSFER_STOPPED,

    /*! Unknown error */
    GMIO_ERROR_UNKNOWN
};

typedef enum gmio_error gmio_error_t;

/*! Returns true if <tt>code == GMIO_NO_ERROR</tt> */
GMIO_INLINE gmio_bool_t gmio_no_error(int code)
{ return code == GMIO_ERROR_OK ? GMIO_TRUE : GMIO_FALSE; }

/*! Returns true if <tt>code != GMIO_NO_ERROR</tt> */
GMIO_INLINE gmio_bool_t gmio_error(int code)
{ return code != GMIO_ERROR_OK ? GMIO_TRUE : GMIO_FALSE; }

#endif /* GMIO_ERROR_H */
