# $NetBSD: Makefile,v 1.5 2013/12/02 18:59:40 jihbed Exp $

DISTNAME=	HepMC-2.06.09
PKGNAME=	${DISTNAME:S/H/h/S/MC/mc/}
CATEGORIES=	math
MASTER_SITES=	http://lcgapp.cern.ch/project/simu/HepMC/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://lcgapp.cern.ch/project/simu/HepMC/
COMMENT=	C++ Event Record for Monte Carlo Generators
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
#USE_CMAKE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=	--with-momentum=GEV
CONFIGURE_ARGS+=	--with-length=CM

.include "../../mk/bsd.pkg.mk"
