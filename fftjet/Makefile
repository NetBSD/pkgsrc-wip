# $NetBSD: Makefile,v 1.2 2012/09/28 23:21:47 asau Exp $
#

DISTNAME=	fftjet-1.3.1
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/fftjet/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/fftjet/
COMMENT=	Multiresolution jet reconstruction in the Fourier domain

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

BUILDLINK_TRANSFORM+=    rm:-fpermissive

PKGCONFIG_OVERRIDE+=	fftjet.pc.in

BUILDLINK_API_DEPENDS.fftw+=	fftw>=3.0
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
