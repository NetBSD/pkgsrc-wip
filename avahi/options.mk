# $NetBSD: options.mk,v 1.4 2008/05/22 15:38:46 tnn2 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avahi

PKG_SUPPORTED_OPTIONS=	dbus glib gdbm python gtk python-gtk python-dbus
PKG_SUPPORTED_OPTIONS+=	avahi-howl expat
PKG_SUGGESTED_OPTIONS=	expat

.include "../../mk/bsd.options.mk"

###
### Some basic dependencies for avahi:
###
### libdaemon + expat = 		avahi-daemon	(default)
### libdaemon + expat = 		avahi-dnsconfd	(default)
### avahi-daemon + dbus = 		libavahi-client
### avahi-daemon + dbus = 		avahi-utils
### python + python-gtk + python-dbus = avahi-python
###

###
### Enable py-dbus support (implies python and dbus)
###
.if !empty(PKG_OPTIONS:Mpython-dbus)
PKG_OPTIONS+=		python dbus
.  include "../../lang/python/pyversion.mk"
.  include "../../sysutils/py-dbus/buildlink3.mk"
DEPENDS+=		${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
PLIST_SRC+=		${PKGDIR}/PLIST.pydbus
.else
CONFIGURE_ARGS+=	--disable-python-dbus
.endif

###
### Enable pygtk support (implies python and gtk)
###
.if !empty(PKG_OPTIONS:Mpython-gtk)
PKG_OPTIONS+=		python gtk
.  include "../../x11/py-gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pygtk
.endif

###
### Enable compatibility layer for HOWL
###
.if !empty(PKG_OPTIONS:Mavahi-howl)
CONFIGURE_ARGS+=	--enable-compat-howl
.endif

###
### Enable expat support
###
.if !empty(PKG_OPTIONS:Mexpat)
.  include "../../textproc/expat/buildlink3.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.expat
.else
CONFIGURE_ARGS+=	--disable-expat
.endif

###
### Enable gtk support (implies glib)
### This will get you avahi-discover-standalone
###
.if !empty(PKG_OPTIONS:Mgtk)
PKG_OPTIONS+=		glib
.  include "../../x11/gtk2/buildlink3.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

###
### Enable glib support
###
.if !empty(PKG_OPTIONS:Mglib)
.  include "../../devel/glib2/buildlink3.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.glib
.else
CONFIGURE_ARGS+=	--disable-glib
.endif

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
.  include "../../lang/python/application.mk"
PYTHON_VERSIONS_ACCEPTED=	25 24
PLIST_SRC+=		${PKGDIR}/PLIST.python
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
.else
CONFIGURE_ARGS+=	--disable-python
.endif

###
### Enable gdbm support
###
.if !empty(PKG_OPTIONS:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gdbm
.endif

###
### Enable DBUS support
###
.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

###
### If python, python-gtk and python-dbus are all enabled you get avahi-python
###
.if !empty(PKG_OPTIONS:Mpython) && !empty(PKG_OPTIONS:Mpython-gtk) \
	&& !empty(PKG_OPTIONS:Mpython-dbus)
PLIST_SRC+=		${PKGDIR}/PLIST.avahipy
.endif

###
### If python, and gdbm are enabled we need py-gdbm as well
###
.if !empty(PKG_OPTIONS:Mpython) && !empty(PKG_OPTIONS:Mgdbm)
DEPENDS+=	${PYPKGPREFIX}-gdbm-[0-9]*:../../databases/py-gdbm
PLIST_SRC+=	${PKGDIR}/PLIST.pygdbm
.endif
