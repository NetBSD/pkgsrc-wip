# $NetBSD$

DISTNAME=	elpa-2022.05.001
CATEGORIES=	math parallel
MASTER_SITES=	https://elpa.mpcdf.mpg.de/software/tarball-archive/Releases/2022.05.001/

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://elpa.mpcdf.mpg.de/
COMMENT=	Eigenvalue soLvers for Petaflop Applications
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config perl
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=	FC=mpifort CPP=cpp

PKGCONFIG_OVERRIDE+=	elpa.pc.in

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../math/scalapack/buildlink3.mk"

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
