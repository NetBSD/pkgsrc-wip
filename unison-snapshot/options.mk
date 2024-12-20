# $NetBSD: options.mk,v 1.9 2024/05/07 23:52:11 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unison
PKG_SUPPORTED_OPTIONS=	lablgtk libinotify
PKG_SUGGESTED_OPTIONS=	lablgtk

# monitor is a PLIST var for any of the reasons why unison-fsmonitor is built
PLIST_VARS+=	gtk3 monitor

# Extend to systems as they are tested to build fsmonitor
.if ${MACHINE_PLATFORM:MNetBSD-*}
PKG_SUGGESTED_OPTIONS+=	libinotify
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlablgtk)
PLIST.gtk3=	yes
DEPENDS+=	font-schumacher-misc>=1.0:../../fonts/font-schumacher-misc

.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibinotify)
PLIST.monitor=	yes

.include "../../devel/libinotify/buildlink3.mk"
.endif

# \todo Probably, enable monitor on GNU/Linux.
# \todo Probably, enable monitor on SunOS.
