# $NetBSD: Makefile,v 1.2 2004/01/25 02:23:32 grantbeattie Exp $
#

DISTNAME=	lash-0.12.1
CATEGORIES=	shells
MASTER_SITES=	http://lash.kerneled.com/devel/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://lash.kerneled.com/
COMMENT=	Modular slighty shell with alias and interfaces

USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes
PKG_SHELL=	${PREFIX}/bin/lash

MAKEFILE=	makefile
ALL_TARGET=	lash

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lash ${PREFIX}/bin/lash
	${INSTALL_PROGRAM} ${WRKSRC}/lagot ${PREFIX}/bin/lagot

.include "../../mk/bsd.pkg.mk"
