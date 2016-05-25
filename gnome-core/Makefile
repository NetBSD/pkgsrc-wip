# $NetBSD: Makefile,v 1.1 2015/07/12 00:20:15 thomasklausner Exp $

DISTNAME=	gnome-core-3.20.2
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for the GNOME core libraries

META_PACKAGE=	yes

# see https://git.gnome.org/browse/
DEPENDS+=	adwaita-icon-theme-[0-9]*:../../graphics/adwaita-icon-theme
DEPENDS+=	at-spi2-atk-[0-9]*:../../devel/at-spi2-atk
DEPENDS+=	at-spi2-core-[0-9]*:../../devel/at-spi2-core
DEPENDS+=	atk-[0-9]*:../../devel/atk
DEPENDS+=	atkmm-[0-9]*:../../devel/atkmm
DEPENDS+=	bijiben-[0-9]*:../../wip/bijiben
DEPENDS+=	cantarell-fonts-[0-9]*:../../fonts/cantarell-fonts
DEPENDS+=	caribou-[0-9]*:../../wip/caribou
DEPENDS+=	clutter-[0-9]*:../../graphics/clutter
DEPENDS+=	clutter-gst-[0-9]*:../../wip/clutter-gst
DEPENDS+=	clutter-gtk-[0-9]*:../../graphics/clutter-gtk
DEPENDS+=	cogl-[0-9]*:../../graphics/cogl
DEPENDS+=	dconf-[0-9]*:../../devel/dconf
DEPENDS+=	dconf-editor-[0-9]*:../../devel/dconf-editor
DEPENDS+=	epiphany-[0-9]*:../../wip/epiphany
DEPENDS+=	evince3-[0-9]*:../../print/evince3
DEPENDS+=	evolution-data-server-[0-9]*:../../wip/evolution-data-server
DEPENDS+=	libfolks-[0-9]*:../../wip/libfolks
DEPENDS+=	gcr-[0-9]*:../../wip/gcr
DEPENDS+=	gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2 #TODO obsolete graphics/gdk-pixbuf?
DEPENDS+=	gdm-[0-9]*:../../wip/gdm
DEPENDS+=	geocode-glib-[0-9]*:../../wip/geocode-glib
DEPENDS+=	gjs-[0-9]*:../../wip/gjs
DEPENDS+=	glib2-[0-9]*:../../devel/glib2
DEPENDS+=	glibmm-[0-9]*:../../devel/glibmm
DEPENDS+=	gmime-[0-9]*:../../mail/gmime
DEPENDS+=	gnome-backgrounds-[0-9]*:../../wip/gnome-backgrounds
DEPENDS+=	gnome-bluetooth-[0-9]*:../../wip/gnome-bluetooth
# TODO gnome-characters
# TODO gnome-contacts
DEPENDS+=	gnome-control-center-[0-9]*:../../wip/gnome-control-center
DEPENDS+=	gnome-desktop3-[0-9]*:../../x11/gnome-desktop3
# TODO gnome-disk-utility
# TODO gnome-font-viewer
DEPENDS+=	gnome-js-common-[0-9]*:../../wip/gnome-js-common
DEPENDS+=	gnome-keyring-[0-9]*:../../wip/gnome-keyring
DEPENDS+=	gnome-menus-[0-9]*:../../wip/gnome-menus
DEPENDS+=	gnome-online-accounts-[0-9]*:../../net/gnome-online-accounts
# TODO gnome-online-miners
DEPENDS+=	gnome-packagekit-[0-9]*:../../pkgtools/gnome-packagekit
# TODO gnome-screenshot
DEPENDS+=	gnome-session-[0-9]*:../../wip/gnome-session
DEPENDS+=	gnome-settings-daemon-[0-9]*:../../wip/gnome-settings-daemon
# TODO gnome-shell
# TODO gnome-shell-extensions
# TODO gnome-shell-sass
DEPENDS+=	gnome-system-monitor-[0-9]*:../../sysutils/gnome-system-monitor
DEPENDS+=	gnome-terminal-[0-9]*:../../wip/gnome-terminal
# TODO gnome-themes-standard
# TODO gnome-todo
DEPENDS+=	gnome-user-docs-[0-9]*:../../misc/gnome-user-docs
# TODO gnome-user-share
# TODO gnome-video-effects
DEPENDS+=	gobject-introspection-[0-9]*:../../devel/gobject-introspection
DEPENDS+=	grilo-plugins-[0-9]*:../../wip/grilo-plugins
DEPENDS+=	gsettings-desktop-schemas-[0-9]*:../../sysutils/gsettings-desktop-schemas
DEPENDS+=	gssdp-[0-9]*:../../net/gssdp
#TODO gstreamermm
# gtk+?
DEPENDS+=	gtk3-[0-9]*:../../x11/gtk3
DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
DEPENDS+=	gtkmm3-[0-9]*:../../x11/gtkmm3
DEPENDS+=	gtksourceview3-[0-9]*:../../x11/gtksourceview3 # TODO obsolete x11/gtksourceview?
DEPENDS+=	gucharmap-[0-9]*:../../fonts/gucharmap
DEPENDS+=	gupnp-[0-9]*:../../net/gupnp
DEPENDS+=	gupnp-igd-[0-9]*:../../net/gupnp-igd
DEPENDS+=	gnome-tracker-[0-9]*:../../wip/gnome-tracker

# TODO

.include "../../mk/bsd.pkg.mk"
