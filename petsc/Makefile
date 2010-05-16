# $NetBSD: Makefile,v 1.3 2010/05/16 19:38:55 asau Exp $
#

DISTNAME=	petsc-3.1-p2
PKGNAME=	petsc-3.1p2
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.mcs.anl.gov/petsc/petsc-as/
COMMENT=	Portable, Extensible Toolkit for  Scientific Computation
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	config/configure.py

MAKE_FILE=		makefile
BUILD_MAKE_FLAGS+=	PETSC_DIR=${WRKSRC}

.include "../../lang/python/pyversion.mk" # get python
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
