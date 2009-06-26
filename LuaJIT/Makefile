# $NetBSD: Makefile,v 1.1.1.1 2009/06/26 01:48:08 phonohawk Exp $
#

DISTNAME=	LuaJIT-1.1.5
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

MAKE_FLAGS+=	INSTALL_TOP=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
BUILD_TARGET = linux

.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
BUILD_TARGET = bsd

.elif ${OPSYS} == "Darwin"
BUILD_TARGET = macosx

.elif ${OPSYS} == "SunOS"
BUILD_TARGET = solaris

.else
BUILD_TARGET = posix
.endif

.include "../../mk/bsd.pkg.mk"
