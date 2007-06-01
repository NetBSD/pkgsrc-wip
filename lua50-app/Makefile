# $NetBSD: Makefile,v 1.1.1.1 2007/06/01 20:11:56 hoka_adam Exp $

DISTNAME=	bsdinstaller-20070528
PKGNAME=	lua50-app-0.1
CATEGORIES=	devel

MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/lib/lua/app

MAINTAINER=	adam.hoka@gmail.com
COMMENT=	App framework for Lua 5.0.x

do-build:
	@${ECHO} "No building required."

do-install:
	${INSTALL_DATA} ${WRKSRC}/app.lua ${PREFIX}/share/lua/5.0/app.lua

.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../wip/lua50-posix/buildlink3.mk"
.include "../../wip/lua50-filename/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
