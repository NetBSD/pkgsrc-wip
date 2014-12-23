# $NetBSD: options.mk,v 1.1 2014/12/23 20:56:06 nros Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.abiword
PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3
PKG_SUPPORTED_OPTIONS=		debug
PKG_SUGGESTED_OPTIONS=		gtk3
.include "../../mk/bsd.options.mk"

#
# Enable debugging funcionality
# more verbose terminal output
#
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.endif

#
# Use GTK+ version 2
#
.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--with-gtk2
.include "../../x11/gtk2/buildlink3.mk"
.endif

#
# Use GTK+ version 3
#
.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
.endif
