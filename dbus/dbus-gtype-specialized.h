/* -*- mode: C; c-file-style: "gnu" -*- */
/* dbus-gtype-specialized.h: Non-DBus-specific functions for specialized GTypes
 *
 * Copyright (C) 2005 Red Hat, Inc.
 *
 * Licensed under the Academic Free License version 2.1
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef DBUS_GOBJECT_TYPE_SPECIALIZED_H
#define DBUS_GOBJECT_TYPE_SPECIALIZED_H

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

G_DEPRECATED_FOR(GVariant)
GType          dbus_g_type_get_collection                   (const char *container,
							     GType       specialization);
G_DEPRECATED_FOR(GVariant)
GType          dbus_g_type_get_map                          (const char *container,
							     GType       key_specialization,
							     GType       value_specialization);
G_DEPRECATED_FOR(GVariant)
GType          dbus_g_type_get_structv                      (const char *container,
							     guint       num_members,
							     GType      *types);
G_DEPRECATED_FOR(GVariant)
GType          dbus_g_type_get_struct                       (const char *container,
                                                             GType       first_type,
                                                             ...);
G_DEPRECATED_FOR(GVariant)
gboolean       dbus_g_type_is_collection                    (GType       gtype);
G_DEPRECATED_FOR(GVariant)
gboolean       dbus_g_type_is_map                           (GType       gtype);
G_DEPRECATED_FOR(GVariant)
gboolean       dbus_g_type_is_struct                        (GType       gtype);
G_DEPRECATED_FOR(GVariant)
GType          dbus_g_type_get_collection_specialization    (GType       gtype);
G_DEPRECATED_FOR(GVariant)
GType          dbus_g_type_get_map_key_specialization       (GType       gtype);
G_DEPRECATED_FOR(GVariant)
GType          dbus_g_type_get_map_value_specialization     (GType       gtype);
G_DEPRECATED_FOR(GVariant)
GType          dbus_g_type_get_struct_member_type           (GType       gtype,
                                                             guint       member);
G_DEPRECATED_FOR(GVariant)
guint          dbus_g_type_get_struct_size                  (GType       gtype);

typedef void   (*DBusGTypeSpecializedCollectionIterator)    (const GValue *value,
							     gpointer      user_data)
  G_GNUC_DEPRECATED;
typedef void   (*DBusGTypeSpecializedMapIterator)           (const GValue *key_val,
							     const GValue *value_val,
							     gpointer      user_data)
  G_GNUC_DEPRECATED;

G_DEPRECATED
gpointer       dbus_g_type_specialized_construct            (GType gtype);

typedef struct {
  /* public */
  GValue *val;
  GType specialization_type;
  /*< private >*/
  /* padding */
  gpointer b;
  guint c;
  gpointer d;
} DBusGTypeSpecializedAppendContext G_GNUC_DEPRECATED;

G_DEPRECATED_FOR(GVariant)
void           dbus_g_type_specialized_init_append             (GValue *value, DBusGTypeSpecializedAppendContext *ctx);

G_DEPRECATED_FOR(GVariant)
void           dbus_g_type_specialized_collection_append       (DBusGTypeSpecializedAppendContext *ctx, GValue *elt);

G_DEPRECATED_FOR(GVariant)
void           dbus_g_type_specialized_collection_end_append   (DBusGTypeSpecializedAppendContext *ctx);

G_DEPRECATED_FOR(GVariant)
void           dbus_g_type_specialized_map_append              (DBusGTypeSpecializedAppendContext *ctx,
								GValue                            *key,
								GValue                            *val);
								

G_DEPRECATED_FOR(GVariant)
gboolean       dbus_g_type_collection_get_fixed             (GValue                                 *value,
							     gpointer                               *data_ret,
							     guint                                  *len_ret);

G_DEPRECATED_FOR(GVariant)
void           dbus_g_type_collection_value_iterate         (const GValue                           *value,
							     DBusGTypeSpecializedCollectionIterator  iterator,
							     gpointer                                user_data);

G_DEPRECATED_FOR(GVariant)
void           dbus_g_type_map_value_iterate                (const GValue                           *value,
							     DBusGTypeSpecializedMapIterator         iterator,
							     gpointer                                user_data);

G_DEPRECATED_FOR(GVariant)
gboolean       dbus_g_type_struct_get_member            (const GValue *value,
                                                         guint member,
                                                         GValue *dest);
G_DEPRECATED_FOR(GVariant)
gboolean       dbus_g_type_struct_set_member            (GValue *value,
                                                         guint member,
                                                         const GValue *src);

G_DEPRECATED_FOR(GVariant)
gboolean       dbus_g_type_struct_get                   (const GValue *value,
                                                         guint member,
                                                         ...);

G_DEPRECATED_FOR(GVariant)
gboolean       dbus_g_type_struct_set                   (GValue *value,
                                                         guint member,
                                                         ...);

typedef gpointer (*DBusGTypeSpecializedConstructor)     (GType type)
  G_GNUC_DEPRECATED;
typedef void     (*DBusGTypeSpecializedFreeFunc)        (GType type, gpointer val)
  G_GNUC_DEPRECATED;
typedef gpointer (*DBusGTypeSpecializedCopyFunc)        (GType type, gpointer src)
  G_GNUC_DEPRECATED;

typedef struct {
  DBusGTypeSpecializedConstructor    constructor;
  DBusGTypeSpecializedFreeFunc       free_func;
  DBusGTypeSpecializedCopyFunc       copy_func;
  GDestroyNotify                     simple_free_func; /* for type-independent freeing if possible */
  /*<private>*/
  gpointer                           padding2;
  gpointer                           padding3;
} DBusGTypeSpecializedVtable G_GNUC_DEPRECATED;

typedef gboolean (*DBusGTypeSpecializedCollectionFixedAccessorFunc) (GType type, gpointer instance, gpointer *values, guint *len)
  G_GNUC_DEPRECATED;
typedef void     (*DBusGTypeSpecializedCollectionIteratorFunc)      (GType type, gpointer instance, DBusGTypeSpecializedCollectionIterator iterator, gpointer user_data)
  G_GNUC_DEPRECATED;
typedef void     (*DBusGTypeSpecializedCollectionAppendFunc)        (DBusGTypeSpecializedAppendContext *ctx, GValue *val)
  G_GNUC_DEPRECATED;
typedef void     (*DBusGTypeSpecializedCollectionEndAppendFunc)     (DBusGTypeSpecializedAppendContext *ctx)
  G_GNUC_DEPRECATED;

typedef struct {
  DBusGTypeSpecializedVtable                        base_vtable;
  DBusGTypeSpecializedCollectionFixedAccessorFunc   fixed_accessor;
  DBusGTypeSpecializedCollectionIteratorFunc        iterator;
  DBusGTypeSpecializedCollectionAppendFunc          append_func;
  DBusGTypeSpecializedCollectionEndAppendFunc       end_append_func;
} DBusGTypeSpecializedCollectionVtable G_GNUC_DEPRECATED;

typedef void (*DBusGTypeSpecializedMapIteratorFunc) (GType type, gpointer instance, DBusGTypeSpecializedMapIterator iterator, gpointer user_data)
  G_GNUC_DEPRECATED;
typedef void (*DBusGTypeSpecializedMapAppendFunc)   (DBusGTypeSpecializedAppendContext *ctx, GValue *key, GValue *val)
  G_GNUC_DEPRECATED;

typedef struct {
  DBusGTypeSpecializedVtable                        base_vtable;
  DBusGTypeSpecializedMapIteratorFunc               iterator;
  DBusGTypeSpecializedMapAppendFunc                 append_func;
} DBusGTypeSpecializedMapVtable G_GNUC_DEPRECATED;

typedef gboolean (*DBusGTypeSpecializedStructGetMember) (GType type, gpointer instance, guint member, GValue *ret_value)
  G_GNUC_DEPRECATED;
typedef gboolean (*DBusGTypeSpecializedStructSetMember) (GType type, gpointer instance, guint member, const GValue *new_value)
  G_GNUC_DEPRECATED;

typedef struct {
  DBusGTypeSpecializedVtable                        base_vtable;
  DBusGTypeSpecializedStructGetMember               get_member;
  DBusGTypeSpecializedStructSetMember               set_member;
} DBusGTypeSpecializedStructVtable G_GNUC_DEPRECATED;

G_DEPRECATED
void           dbus_g_type_specialized_init           (void);

G_DEPRECATED
void           dbus_g_type_register_collection        (const char                                   *name,
						       const DBusGTypeSpecializedCollectionVtable   *vtable,
						       guint                                         flags);
  
G_DEPRECATED
void           dbus_g_type_register_map               (const char                                   *name,
						       const DBusGTypeSpecializedMapVtable          *vtable,
						       guint                                         flags);

G_DEPRECATED
void           dbus_g_type_register_struct             (const char                                   *name,
						       const DBusGTypeSpecializedStructVtable        *vtable,
						       guint                                          flags);

G_DEPRECATED
const DBusGTypeSpecializedMapVtable* dbus_g_type_map_peek_vtable (GType map_type);
G_DEPRECATED
const DBusGTypeSpecializedCollectionVtable* dbus_g_type_collection_peek_vtable (GType collection_type);

G_DEPRECATED
const DBusGTypeSpecializedStructVtable* dbus_g_type_struct_peek_vtable (GType struct_type);

G_DEPRECATED
GVariant *dbus_g_value_build_g_variant (const GValue *value);

G_END_DECLS

#endif
