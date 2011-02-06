/* Password text box for GTK
 * Copyright (C) 2011 Niklas Hambuechen
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
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#ifndef __GTK_PASSWORD_ENTRY_H__
#define __GTK_PASSWORD_ENTRY_H__


#include <glib.h>
#include <glib-object.h>


G_BEGIN_DECLS

#define GTK_TYPE_PASSWORD_ENTRY                  (gtk_entry_get_type ())
#define GTK_PASSWORD_ENTRY(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_PASSWORD_ENTRY, GtkPasswordEntry))
#define GTK_PASSWORD_ENTRY_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_PASSWORD_ENTRY, GtkPasswordEntryClass))
#define GTK_IS_PASSWORD_ENTRY(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_PASSWORD_ENTRY))
#define GTK_IS_PASSWORD_ENTRY_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_PASSWORD_ENTRY))
#define GTK_PASSWORD_ENTRY_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_PASSWORD_ENTRY, GtkEntryClass))


typedef struct _GtkPasswordEntry       GtkPasswordEntry;
typedef struct _GtkPasswordEntryClass  GtkPasswordEntryClass;

struct _GtkPasswordEntry
{
  GtkEntry entry;
};

struct _GtkPasswordEntryClass
{
  GtkEntryClass parent_class;

  void (* gtk_password_entry) (GtkPasswordEntry *gpe);
};

GType          gtk_password_entry_get_type        (void);
GtkWidget*     gtk_password_entry_new             (void);
void	       gtk_password_entry_clear           (GtkPasswordEntry *gpe);

G_END_DECLS

#endif /* __GTK_PASSWORD_ENTRY_H__ */
