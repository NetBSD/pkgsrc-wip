# $NetBSD: Makefile,v 1.4 2012/11/23 22:34:05 othyro Exp $
#

DISTNAME=	spai-3.2
CATEGORIES=	math
MASTER_SITES=	http://www.computational.unibas.ch/software/spai/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.computational.unibas.ch/software/spai/
COMMENT=	Sparse Approximate Inverses
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	NO

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash:run
CONFIG_SHELL=	bash
USE_LANGUAGES=	c fortran

CONFIGURE_ARGS+=	--with-mpi=${BUILDLINK_PREFIX.mpi}

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
