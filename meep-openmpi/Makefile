# $NetBSD: Makefile,v 1.4 2013/06/25 12:49:00 outpaddling Exp $
#

DISTNAME=	meep-1.2
PKGNAME=	meep-openmpi-1.2
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/meep/
COMMENT=	FDTD simulation software to model electromagnetic systems
LICENSE=	gnu-gpl-v3

DEPENDS+=	bash-[0-9]*:../../shells/bash

# GNU_CONFIGURE overrides --prefix
HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran77

CONFIGURE_ARGS+=	--with-libctl=${PREFIX}/share/libctl \
			--with-mpi \
			--prefix=${MPI_PREFIX:Q} \
			--mandir=${MPI_PREFIX:Q}/man

MESSAGE_SUBST+=		PREFIX=${PREFIX}

.include "../../wip/mpb-openmpi/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
# Should this be satisfied by fftw2-openmpi from mpb-openmpi?
.include "../../math/fftw2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../math/harminv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/openmpi163/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
