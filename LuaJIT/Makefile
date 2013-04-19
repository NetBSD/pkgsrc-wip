# $NetBSD: Makefile,v 1.3 2013/04/19 18:38:49 alnsn Exp $
#

DISTNAME=	LuaJIT-2.0.1
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://luajit.org/download/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

# LuaJIT uses non-standard MAP_32BIT on Linux and a dirty hack on FreeBSD.
# XXX Look into applying FreeBSD hack to NetBSD.
NOT_FOR_PLATFORM=	NetBSD-*-x86_64

USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
