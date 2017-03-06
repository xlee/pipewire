/* Simple Plugin API
 * Copyright (C) 2016 Wim Taymans <wim.taymans@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __PINOS_CONNECTION_H__
#define __PINOS_CONNECTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <spa/defs.h>

typedef struct _PinosConnection PinosConnection;

PinosConnection *  pinos_connection_new             (int              fd);
void               pinos_connection_destroy         (PinosConnection *conn);

int                pinos_connection_add_fd          (PinosConnection *conn,
                                                     int              fd);
int                pinos_connection_get_fd          (PinosConnection *conn,
                                                     int              index);

bool               pinos_connection_get_next        (PinosConnection  *conn,
                                                     uint8_t          *opcode,
                                                     uint32_t         *dest_id,
                                                     void            **data,
                                                     size_t           *size);

void *             pinos_connection_begin_write     (PinosConnection  *conn,
                                                     size_t            size);
void               pinos_connection_end_write       (PinosConnection  *conn,
                                                     uint32_t          dest_id,
                                                     uint8_t           opcode,
                                                     size_t            size);

bool               pinos_connection_flush           (PinosConnection  *conn);
bool               pinos_connection_clear           (PinosConnection  *conn);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* __PINOS_CONNECTION_H__ */
