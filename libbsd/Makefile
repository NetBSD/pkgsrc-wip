# $NetBSD: Makefile,v 1.1 2013/01/03 21:11:34 mrampke Exp $

DISTNAME=	libbsd-0.10.0
MASTER_SITES=	http://libbsd.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

CATEGORIES=	devel

HOMEPAGE=	https://libbsd.freedesktop.org/
COMMENT=	Compatibility library for BSD functions under other systems
LICENSE=	original-bsd
MAINTAINER=	matthias@rampke.de

.include "Makefile.common"
ONLY_FOR_PLATFORM= ${LIBBSD.only_for_platform}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
