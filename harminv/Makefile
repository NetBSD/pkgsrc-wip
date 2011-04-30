# $NetBSD: Makefile,v 1.1.1.1 2011/04/30 21:33:59 jihbed Exp $
#

DISTNAME=	harminv-1.3.1
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/harminv/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ab-initio.mit.edu/wiki/index.php/Harminv
COMMENT= Solver of harmonic inversion
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=  c c++ fortran77

PKGCONFIG_OVERRIDE+=	harminv.pc.in

EVAL_PREFIX+=		MPCOMPLEX_PREFIX=mpc
CONFIGURE_ARGS+=	--with-cxx=${MPCOMPLEX_PREFIX_PREFIX}/include
BUILDLINK_API_DEPENDS.mpcomplex+=	mpcomplex>=0.8.2
.include "../../math/mpcomplex/buildlink3.mk"

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
