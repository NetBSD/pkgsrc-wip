# $NetBSD: options.mk,v 1.1.1.1 2005/12/02 10:59:14 ghen Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.firefox
PKG_SUPPORTED_OPTIONS=		official-mozilla-branding
PKG_OPTIONS_REQUIRED_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk1 gtk2 qt3 xlib
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

### Enable Official mozilla.org Branding
### Note that you cannot distribute builds with Official Branding
### without permission of the Mozilla Foundation.
### See http://www.mozilla.org/foundation/trademarks/
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
CONFIGURE_ARGS+=		--enable-official-branding
RESTRICTED=			"Cannot redistribute builds with Official Branding"
NO_BIN_ON_CDROM=		${RESTRICTED}
NO_BIN_ON_FTP=			${RESTRICTED}
.endif

### Build with GTK1 toolkit
.if !empty(PKG_OPTIONS:Mgtk1)
CONFIGURE_ARGS+=		--enable-default-toolkit=gtk
.include "../../x11/gtk/buildlink3.mk"
MOZILLA?=			firefox-gtk1
PLIST_SRC+=			PLIST.gtk1
.endif

### Build with GTK2 toolkit (the default)
.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=		--enable-default-toolkit=gtk2
.include "../../x11/gtk2/buildlink3.mk"
MOZILLA?=			firefox
PLIST_SRC+=			PLIST.gtk2
.endif

### Build with Qt toolkit -- not supported
.if !empty(PKG_OPTIONS:Mqt3)
CONFIGURE_ARGS+=		--enable-default-toolkit=qt
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	build
MOZILLA?=			firefox-qt3
PLIST_SRC+=			PLIST.qt3
.endif

### Build with plain Xlib toolkit -- not supported
.if !empty(PKG_OPTIONS:Mxlib)
CONFIGURE_ARGS+=		--enable-default-toolkit=xlib
.include "../../mk/x11.buildlink3.mk"
MOZILLA?=			firefox-xlib
PLIST_SRC+=			PLIST.xlib
.endif
