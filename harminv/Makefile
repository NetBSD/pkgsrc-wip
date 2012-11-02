# $NetBSD: Makefile,v 1.7 2012/11/02 18:06:33 outpaddling Exp $
#

DISTNAME=	harminv-1.3.1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/harminv/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/harminv/
COMMENT=	Program and library to solve the problem of harmonic inversion
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++ fortran77

PKGCONFIG_OVERRIDE+=	harminv.pc.in

# From jihbed's package.  Don't appear to be necessary
#EVAL_PREFIX+=		MPCOMPLEX_PREFIX=mpc
#CONFIGURE_ARGS+=	--with-cxx=${MPCOMPLEX_PREFIX_PREFIX}/include
#BUILDLINK_API_DEPENDS.mpcomplex+=	mpcomplex>=0.8.2
#.include "../../math/mpcomplex/buildlink3.mk"

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
