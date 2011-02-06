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
#include <gtk/gtksignal.h>
#include <gtk/gtkentry.h>
#include "gtkpasswordentry.h"

static void gtk_password_entry_class_init          (GtkPasswordEntryClass *klass);
static void gtk_password_entry_init                (GtkPasswordEntry      *gpe);
static void gtk_password_entry_toggle_visibility   (GtkPasswordEntry *gpe);

GType
gtk_password_entry_get_type (void)
{
	static GType gpe_type = 0;

	if (!gpe_type)
	{
		static const GtkTypeInfo gpe_info =
		{
			"GtkPasswordEntry",
			sizeof (GtkPasswordEntry),
			sizeof (GtkPasswordEntryClass),
			(GtkClassInitFunc) gtk_password_entry_class_init,
			(GtkObjectInitFunc) gtk_password_entry_init,
			NULL, /* reserved_1 */
			NULL, /* reserved_2 */
			(GtkClassInitFunc) NULL,
		};

		gpe_type = gtk_type_unique (GTK_TYPE_ENTRY, &gpe_info);
	}

	return gpe_type;
}

static void
gtk_password_entry_class_init (GtkPasswordEntryClass *klass)
{
}

static void
gtk_password_entry_init (GtkPasswordEntry *gpe)
{
}

void gtk_password_entry_toggle_visibility (GtkPasswordEntry *gpe)
{
	GtkEntry *entry = GTK_ENTRY(gpe);
	gtk_entry_set_visibility (entry, !gtk_entry_get_visibility (entry));
}

void on_icon_release (GtkPasswordEntry *entry, GtkEntryIconPosition pos,  
	GdkEvent *event, gpointer userdata)  
{  
    if (pos == GTK_ENTRY_ICON_SECONDARY)
    {
    	gtk_password_entry_toggle_visibility (entry);
    }
}  

GtkWidget*
gtk_password_entry_new ()
{
	GtkWidget *widget = GTK_WIDGET (gtk_type_new (GTK_TYPE_PASSWORD_ENTRY));

	gtk_entry_set_visibility (GTK_ENTRY (widget), FALSE);

	gtk_entry_set_icon_from_stock(
		GTK_ENTRY(widget),
		GTK_ENTRY_ICON_SECONDARY,
		GTK_STOCK_DIALOG_AUTHENTICATION
	);

	g_signal_connect(
		GTK_OBJECT(widget),
		"icon-release",
		G_CALLBACK(on_icon_release),
		NULL
	);

	return widget;
}
