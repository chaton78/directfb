/*
   (c) Copyright 2012-2013  DirectFB integrated media GmbH
   (c) Copyright 2001-2013  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>,
              Andreas Shimokawa <andi@directfb.org>,
              Marek Pikarski <mass@directfb.org>,
              Sven Neumann <neo@directfb.org>,
              Ville Syrjälä <syrjala@sci.fi> and
              Claudio Ciccani <klan@users.sf.net>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/



#ifndef __DIRECT__OS__THREAD_H__
#define __DIRECT__OS__THREAD_H__

#include <direct/os/types.h>

/**********************************************************************************************************************/

DirectResult DIRECT_API   direct_thread_init       ( DirectThread *thread );

void         DIRECT_API   direct_thread_deinit     ( DirectThread *thread );

/*
 * Returns the thread of the caller.
 */
DirectThread DIRECT_API  *direct_thread_self       ( void );

/*
 * Returns the name of the calling thread.
 */
const char   DIRECT_API  *direct_thread_self_name  ( void );

/*
 * Changes the name of the calling thread.
 */
void         DIRECT_API   direct_thread_set_name   ( const char   *name );

/*
 * Cancel a running thread.
 */
void         DIRECT_API   direct_thread_cancel     ( DirectThread *thread );

/*
 * Detach a thread.
 */
void         DIRECT_API   direct_thread_detach     ( DirectThread *thread );

/*
 * Check if the calling thread is canceled.
 * Must not be called by other threads than 'thread'.
 * This function won't return if the thread is canceled.
 */
void         DIRECT_API   direct_thread_testcancel ( DirectThread *thread );

/*
 * Wait until a running thread is terminated.
 */
void         DIRECT_API   direct_thread_join       ( DirectThread *thread );

void         DIRECT_API   direct_thread_kill       ( DirectThread *thread,
                                                     int           signal );


void         DIRECT_API   direct_thread_sleep      ( long long     micros );

#endif

