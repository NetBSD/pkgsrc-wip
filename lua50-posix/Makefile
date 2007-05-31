# $NetBSD: Makefile,v 1.1.1.1 2007/05/31 19:34:24 hoka_adam Exp $

DISTNAME=	lposix
PKGNAME=	lua50-posix-1.0
CATEGORIES=	devel
WRKSRC=		${WRKDIR}/posix
MASTER_SITES=	http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.0/

MAINTAINER=	adam.hoka@gmail.com
COMMENT=	POSIX bindings for Lua 5.0.x

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lposix.so ${PREFIX}/lib/lua/5.0/
	${INSTALL_DATA} ${WRKSRC}/posix.lua ${PREFIX}/share/lua/5.0/

.include "../../wip/lua50/buildlink3.mk"
.include "../../wip/lua50-compat51/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
