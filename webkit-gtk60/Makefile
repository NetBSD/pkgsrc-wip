# $NetBSD: Makefile,v 1.240 2022/11/23 16:19:06 adam Exp $

PLIST_SRC=	PLIST

.include "../../wip/webkit-gtk41/Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk60/}

COMMENT=	GTK4 port of the WebKit browser engine (API 6.0)

# this enables the 6.0 API
CMAKE_CONFIGURE_ARGS+=		-DUSE_GTK4=ON

# Needed for JavaScript JIT
NOT_PAX_MPROTECT_SAFE+=		libexec/webkitgtk-6.0/MiniBrowser
NOT_PAX_MPROTECT_SAFE+=		libexec/webkitgtk-6.0/WebKitWebProcess
#NOT_PAX_MPROTECT_SAFE+=	libexec/webkitgtk-6.0/WebKitNetworkProcess
NOT_PAX_MPROTECT_SAFE+=		libexec/webkitgtk-6.0/jsc

.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
