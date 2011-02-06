import gtk

class PasswordEntry(gtk.Entry):
	"""A text box for passwords, displayed as bullets by default, with an icon to show the password in plain text."""
	def __init__(self, *args, **kwargs):
		gtk.Entry.__init__(self, *args, **kwargs)
		self.set_visibility(False)
		self.set_property('secondary-icon-stock', gtk.STOCK_DIALOG_AUTHENTICATION)
		self.set_property('secondary-icon-tooltip-text', "Show password")
		self.connect('icon-release', lambda *args: self.toggle_visibility())

	def toggle_visibility(self):
		self.set_visibility(not self.get_visibility())
