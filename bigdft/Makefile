# $NetBSD: Makefile,v 1.2 2012/09/24 17:14:31 asau Exp $
#

DISTNAME=	bigdft-1.6.0
CATEGORIES=	math
MASTER_SITES=	http://inac.cea.fr/L_Sim/BigDFT/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://inac.cea.fr/L_Sim/BigDFT/
COMMENT=	Massively parallel electronic structure code using a wavelet basis set
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP=	configure
GNU_CONFIGURE=		yes
USE_TOOLS+=		bash pkg-config gmake
USE_LANGUAGES=		c c++ fortran

PKGCONFIG_OVERRIDE+=	bigdft.pc.in
PKGCONFIG_OVERRIDE+=	libxc-1.1.0/build/libxc.pc.in

CONFIGURE_ARGS+=	--disable-mpi
CONFIGURE_ARGS+=	--disable-internal-libxc

CONFIGURE_ARGS+=	--with-archives
.include "../../archivers/libarchive/buildlink3.mk"
CONFIGURE_ARGS+=	--with-blas
.include "../../math/blas/buildlink3.mk"
CONFIGURE_ARGS+=	--with-lapack
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
