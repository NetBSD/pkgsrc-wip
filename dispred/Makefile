# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:36 asau Exp $
#

DISTNAME=	DISPred-2.0
PKGNAME=	dispred-2.0
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/dispred/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://dispred.hepforge.org/
COMMENT=	Tools for calculating DIS cross sections at LO and NLO in QCD
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++ fortran

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
