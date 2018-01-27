# $NetBSD: Makefile,v 1.4 2012/10/15 19:21:45 asau Exp $
#

DISTNAME=	meep-1.1.1
PKGNAME=	meep-mpi-1.1.1
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/meep/
COMMENT=	FDTD simulation software to model electromagnetic systems
LICENSE=	gnu-gpl-v3

DEPENDS+=	bash-[0-9]*:../../shells/bash

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

# Redirect headers and data to avoid conflict with meep.
# Better to install whole thing to another prefix like mpi/openmpi?
CONFIGURE_ARGS+=	--with-libctl=${PREFIX}/share/libctl \
			--with-mpi \
			--includedir=${PREFIX}/include/meep-mpi \
			--datadir=${PREFIX}/share/meep-mpi

.include "../../wip/mpb/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../math/harminv/buildlink3.mk"
.include "../../parallel/openmpi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
