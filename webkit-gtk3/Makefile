# $NetBSD: Makefile,v 1.3 2015/08/22 12:24:39 leot1990 Exp $

.include "../../www/webkit24-gtk/Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit24-gtk3/}

COMMENT=	GTK3 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=3.0
# Documentation is also installed by webkit24-gtk, avoid conflicts.
CONFIGURE_ARGS+=        --disable-gtk-doc-html
# WebKit 2.0 API is not supported due to build issues.
CONFIGURE_ARGS+=        --disable-webkit2

# gen PLIST from webkit-gtk/PLIST
.PHONY: print-PLIST-from-gtk
print-PLIST-from-gtk:
	${RUN}${SED} 						\
	-e 's/jsc-1/jsc-3/'					\
	-e 's/javascriptcoregtk-1.0/javascriptcoregtk-3.0/'	\
	-e 's/webkit-1.0.pc/webkitgtk-3.0.pc/'			\
	-e 's/webkit-1.0/webkit-3.0/'				\
	-e 's/webkit-2.0/webkit-3.0/'				\
	-e 's/webkitgtk-2.0.mo/webkitgtk-3.0.mo/'		\
	-e 's/webkitgtk-1.0/webkitgtk-3.0/'			\
	-e 's/JSCore-1.0/JSCore-3.0/'				\
	-e 's/WebKit-1.0/WebKit-3.0/'				\
	../../www/webkit-gtk/PLIST

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
