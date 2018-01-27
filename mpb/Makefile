# $NetBSD: Makefile,v 1.10 2013/09/01 17:10:37 asau Exp $
#

DISTNAME=	mpb-1.4.2
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/mpb/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/mpb/
COMMENT=	MIT Photonic Bands
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c fortran77
USE_TOOLS+=	gsed

CONFIGURE_ARGS+=	--with-libctl=${BUILDLINK_PREFIX.libctl}/share/libctl
# Prevent picking up wrong sh:
CONFIGURE_ENV+=		SH_JOB=$(TOOLS_PATH.sh)
CFLAGS+=		-DH5_USE_16_API=1

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libctl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
