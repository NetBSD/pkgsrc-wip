# $NetBSD: Makefile,v 1.2 2012/09/28 23:21:46 asau Exp $
#

DISTNAME=	faast-0.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=defeo/}
GITHUB_PROJECT=	FAAST
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/defeo/FAAST
COMMENT=	Library for Fast Arithmetics in Artin-Schreier Towers
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../math/ntl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
