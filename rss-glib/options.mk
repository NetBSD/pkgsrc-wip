# $NetBSD: options.mk,v 1.6 2014/01/26 15:50:00 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rss-glib

PKG_SUPPORTED_OPTIONS=	python mono vala
PKG_SUGGESTED_OPTIONS=	python mono vala

.include "../../mk/bsd.options.mk"

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2, py-gobject
.  include "../../lang/python/extension.mk"
.  include "../../lang/python/pyversion.mk"
PLIST_SUBST+=			PYSITELIB=${PYSITELIB}
.  include "../../devel/py-gobject/buildlink3.mk"
.  include "../../x11/py-gtk2/buildlink3.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.python
.else
CONFIGURE_ARGS+=	--disable-python
.endif

###
### Enable mono support
###
.if !empty(PKG_OPTIONS:Mmono)
.  include "../../lang/mono2/buildlink3.mk"
.  include "../../x11/gtk-sharp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mono=yes
PLIST_SRC+=		${PKGDIR}/PLIST.mono
.else
CONFIGURE_ARGS+=	--disable-mono
.endif

###
### Enable vala support
###
.if !empty(PKG_OPTIONS:Mvala)
.  include "../../lang/vala/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vala=yes
PLIST_SRC+=		${PKGDIR}/PLIST.vala
.else
CONFIGURE_ARGS+=	--disable-vala
.endif
