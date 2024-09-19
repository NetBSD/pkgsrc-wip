# $NetBSD: Makefile,v 1.2 2014/11/22 10:31:06 jihbed Exp $

DISTNAME=	kstest-2.0.0
CATEGORIES=	math
MASTER_SITES=	https://www.hepforge.org/archive/kstest/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://kstest.hepforge.org/
COMMENT=	Kolmogorov-Smirnov Test Statistic with High Precision
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	kstest.pc.in

.include "../../mk/bsd.pkg.mk"
