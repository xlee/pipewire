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

#ifndef __PINOS_SERIALIZE_H__
#define __PINOS_SERIALIZE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <spa/include/spa/buffer.h>
#include <spa/include/spa/format.h>
#include <spa/include/spa/props.h>
#include <spa/include/spa/port.h>

size_t          pinos_serialize_buffer_get_size       (const SpaBuffer *buffer);
size_t          pinos_serialize_buffer_serialize      (void *dest, const SpaBuffer *buffer);
SpaBuffer *     pinos_serialize_buffer_deserialize    (void *src, off_t offset);
SpaBuffer *     pinos_serialize_buffer_copy_into      (void *dest, const SpaBuffer *buffer);

size_t          pinos_serialize_port_info_get_size    (const SpaPortInfo *info);
size_t          pinos_serialize_port_info_serialize   (void *dest, const SpaPortInfo *info);
SpaPortInfo *   pinos_serialize_port_info_deserialize (void *src, off_t offset);
SpaPortInfo *   pinos_serialize_port_info_copy_into   (void *dest, const SpaPortInfo *info);

#ifdef __cplusplus
}
#endif

#endif /* __PINOS_SERIALIZE_H__ */
