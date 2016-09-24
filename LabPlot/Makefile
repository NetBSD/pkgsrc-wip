# $NetBSD: Makefile,v 1.14 2012/11/13 19:33:44 othyro Exp $
#

DISTNAME=	LabPlot-1.6.0.1-2
PKGREVISION=	3
CATEGORIES=	kde graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=labplot/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://mitarbeiter.mbi-berlin.de/gerlach/Linux/LabPlot/
COMMENT=	Data analysis and visualisation

WRKSRC=			${WRKDIR}/LabPlot-1.6.0.1
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+= --enable-gsl
CONFIGURE_ARGS+= --enable-fftw
CONFIGURE_ARGS+= --enable-ImageMagick
CONFIGURE_ARGS+= --enable-tiff
CONFIGURE_ARGS+= --enable-jasper
CONFIGURE_ARGS+= --disable-ocaml

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
