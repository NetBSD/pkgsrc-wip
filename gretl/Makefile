# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:06 thomasklausner Exp $
#

DISTNAME=	gretl-1.7.4
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gretl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@users.sourceforge.net
HOMEPAGE=	http://gretl.sourceforge.net/
COMMENT=	Gnu Regression, Econometrics and Time-series Library

#USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
BUILD_TARGET=
TEST_TARGET=		check

# Fixing others' bugs:
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif
CONFIGURE_ARGS+=	--disable-gui

# DEPENDENCIES:
.include "options.mk"

DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
