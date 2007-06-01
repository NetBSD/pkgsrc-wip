# $NetBSD: Makefile,v 1.1.1.1 2007/06/01 20:13:26 hoka_adam Exp $

DISTNAME=	bsdinstaller-20070528
PKGNAME=	lua50-filename-0.1
CATEGORIES=	devel

MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/lib/lua/filename

MAINTAINER=	adam.hoka@gmail.com
COMMENT=	Filename-manipulating functions for Lua 5.0.x

do-build:
	@${ECHO} "No building required."

do-install:
	${INSTALL_DATA} ${WRKSRC}/filename.lua ${PREFIX}/share/lua/5.0/filename.lua

.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../wip/lua50-posix/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
