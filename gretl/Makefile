# $NetBSD: Makefile,v 1.11 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=	gretl-1.9.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gretl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@users.sourceforge.net
HOMEPAGE=	http://gretl.sourceforge.net/
COMMENT=	Gnu Regression, Econometrics and Time-series Library

USE_LANGUAGES=		c fortran77	# problems with LAPACK
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
BUILD_TARGET=
TEST_TARGET=		check
USE_PKGLOCALEDIR=	yes

# Fixing others' bugs:
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif
CONFIGURE_ARGS+=	--disable-gui

# DEPENDENCIES:
.include "options.mk"

DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot

# Skip checks temporarily:
CHECK_PORTABILITY_SKIP=	osx/script

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
