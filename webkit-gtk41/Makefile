# $NetBSD: Makefile,v 1.240 2022/11/23 16:19:06 adam Exp $

PLIST_SRC=	PLIST

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk41/}
COMMENT=	GTK3 port of the WebKit browser engine (API 4.1)

CMAKE_CONFIGURE_ARGS+=		-DUSE_GTK4=OFF

# Needed for JavaScript JIT
#NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.1/MiniBrowser
NOT_PAX_MPROTECT_SAFE+=		libexec/webkit2gtk-4.1/WebKitWebProcess
#NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.1/WebKitNetworkProcess
NOT_PAX_MPROTECT_SAFE+=		libexec/webkit2gtk-4.1/jsc

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
