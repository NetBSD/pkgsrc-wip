# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:34 asau Exp $
#

DISTNAME=	genus2reduction-0.3
CATEGORIES=	math
MASTER_SITES=	http://www.math.u-bordeaux.fr/~liu/G2R/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.u-bordeaux.fr/~liu/G2R/
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
