# $NetBSD: Makefile,v 1.1 2015/02/20 13:25:30 yrmt Exp $

GHCOMMIT=	746b6dfc1f8d6deb320b6679f00b78061f4f08e6
DISTNAME=	${GHCOMMIT}
PKGNAME=	asignify-0.1.0.20150220
CATEGORIES=	security
MASTER_SITES=	https://github.com/vstakhov/asignify/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/vstakhov/asignify
COMMENT=	Yet another signify tool
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/asignify-${GHCOMMIT}

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake

pre-configure:
		cd ${WRKSRC}; sh ./autogen.sh

.include "../../mk/bsd.pkg.mk"
