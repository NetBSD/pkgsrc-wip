# $NetBSD: Makefile,v 1.5 2012/10/05 11:12:55 asau Exp $
#

DISTNAME=	petsc-3.1-p2
PKGNAME=	petsc-3.1p2
CATEGORIES=	math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.mcs.anl.gov/petsc/petsc-as/
COMMENT=	Portable, Extensible Toolkit for  Scientific Computation
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
CONFIG_SHELL=		${PYTHONBIN}
# CONFIGURE_SCRIPT=	config/configure.py
CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}

MAKE_FILE=		makefile
BUILD_MAKE_FLAGS+=	PETSC_DIR=${WRKSRC}

.include "../../lang/python/pyversion.mk" # get python
.include "../../mk/blas.buildlink3.mk"
# .include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
