# $NetBSD: Makefile,v 1.4 2012/09/29 17:05:55 asau Exp $
#

DISTNAME=	HepMC-2.06.02
PKGNAME=	${DISTNAME:S/H/h/S/MC/mc/}
CATEGORIES=	math
MASTER_SITES=	http://lcgapp.cern.ch/project/simu/HepMC/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://lcgapp.cern.ch/project/simu/HepMC/
COMMENT=	C++ Event Record for Monte Carlo Generators
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=NO

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=	--with-momentum=GEV
CONFIGURE_ARGS+=	--with-length=CM

.include "../../mk/bsd.pkg.mk"
