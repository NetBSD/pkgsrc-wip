# $NetBSD: options.mk,v 1.1 2014/01/06 23:05:18 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hexchat
PKG_SUPPORTED_OPTIONS=	dbus gtk2 inet6 libcanberra libnotify libpci libproxy
PKG_SUPPORTED_OPTIONS+=	nls ntlm openssl perl python tests themes xft2
PKG_SUGGESTED_OPTIONS+=	gtk2 inet6 libproxy libsexy nls openssl xft2

PKG_OPTIONS_OPTIONAL_GROUPS+=	spell
PKG_OPTIONS_GROUP.spell=	libsexy gtkspell

PLIST_VARS+=		gtk2 libpci nls perl python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
BROKEN=			The dbus option causes the build to stall.
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk2=		yes
.else
CONFIGURE_ARGS+=	--disable-gtkfe --disable-gtktest
.endif

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mlibcanberra)
.include "../../audio/libcanberra/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libcanberra
.endif

.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.if !empty(PKG_OPTIONS:Mlibpci)
.include "../../sysutils/pciutils/buildlink3.mk"
PLIST.libpci=		yes
.endif

.if !empty(PKG_OPTIONS:Mlibproxy)
.include "../../www/libproxy/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libproxy
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mntlm)
.include "../../devel/libntlm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ntlm=yes
.else
CONFIGURE_ARGS+=	--enable-ntlm=no
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-openssl=no
.endif

.if !empty(PKG_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl
PLIST.perl=		yes
.else
CONFIGURE_ARGS+=        --disable-perl
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/pyversion.mk"
PLIST.python=		yes
.else
CONFIGURE_ARGS+=	--enable-python=no
.endif

.if !empty(PKG_OPTIONS:Mlibsexy)
.include "../../devel/libsexy/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-spell=libsexy
.elif !empty(PKG_OPTIONS:Mgtkspell)
.include "../../textproc/gtkspell/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-spell=gtkspell
.else
CONFIGURE_ARGS+=        --enable-spell=static
.endif

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--enable-glibtest
.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-gtktest
.endif
.else
CONFIGURE_ARGS+=	--disable-glibtest --disable-gtktest
.endif

.if !empty(PKG_OPTIONS:Mthemes)
BROKEN=			The themes option does not build at the moment.
.include "../../devel/monodevelop/buildlink3.mk"
CONFIGURE_ARGS+=	--with-theme-manager=on
.endif

.if !empty(PKG_OPTIONS:Mxft2)
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-shm=yes
.else
CONFIGURE_ARGS+=	--enable-shm=no
.endif
