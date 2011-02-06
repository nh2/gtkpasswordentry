import gtk
from gtkpasswordentry import PasswordEntry

window = gtk.Window()
password_entry = PasswordEntry()
window.add(password_entry)
window.show_all()
window.connect("destroy", lambda _: gtk.main_quit())
gtk.main()
