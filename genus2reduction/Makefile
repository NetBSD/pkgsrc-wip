# $NetBSD: Makefile,v 1.3 2013/02/12 18:35:02 shattered Exp $
#

DISTNAME=	genus2reduction-0.3
CATEGORIES=	math
MASTER_SITES=	http://www.math.u-bordeaux.fr/~qliu/G2R/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.math.u-bordeaux.fr/~qliu/G2R/
COMMENT=	Conductor and Reduction Types for Genus 2 Curves
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

INSTALLATIONS_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${GMAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/genus2reduction ${DESTDIR}${PREFIX}/bin/genus2reduction

.include "../../math/pari/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
