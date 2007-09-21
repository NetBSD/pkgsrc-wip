# $NetBSD: Makefile,v 1.4 2007/09/21 13:06:49 thomasklausner Exp $
#

DISTNAME=		LabPlot-1.3.0
PKGREVISION=		1
CATEGORIES=		kde graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=labplot/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://mitarbeiter.mbi-berlin.de/gerlach/Linux/LabPlot/
COMMENT=	Data analysis and visualisation

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --enable-gsl
CONFIGURE_ARGS+= --enable-fftw
CONFIGURE_ARGS+= --enable-ImageMagick
CONFIGURE_ARGS+= --enable-tiff
CONFIGURE_ARGS+= --enable-jasper

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
