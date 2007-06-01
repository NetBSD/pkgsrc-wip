# $NetBSD: Makefile,v 1.3 2007/06/01 18:00:10 hoka_adam Exp $

DISTNAME=	bsdinstaller-20070528
PKGNAME=	lua50-pty-0.1
CATEGORIES=	devel

MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/lib/lua/pty

FILESDIR=	${.CURDIR}/../../wip/bsdinstaller/files

post-extract:
	${CP} ${FILESDIR}/Config ${WRKDIR}/${DISTNAME}/installer/src/Config

MAINTAINER=	adam.hoka@gmail.com
COMMENT=	Pty (pseudo-terminal) bindings for Lua 5.0.x

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lpty.so ${PREFIX}/lib/lua/5.0
	${INSTALL_DATA} ${WRKSRC}/pty.lua ${PREFIX}/share/lua/5.0

.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
