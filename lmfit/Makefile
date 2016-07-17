# $NetBSD$

DISTNAME=	lmfit-6.1
CATEGORIES=	math
MASTER_SITES=	http://apps.jcns.fz-juelich.de/src/lmfit/ \
	http://downloads.sourceforge.net/project/lmfit/lmfit/lmfit-6.1.tgz
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://apps.jcns.fz-juelich.de/doku/sc/lmfit#
COMMENT= 	C library for Levenberg-Marquardt least-squares minimization
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lmfit.pc.in

.include "../../mk/bsd.pkg.mk"
