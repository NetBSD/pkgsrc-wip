# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:04 othyro Exp $
#

DISTNAME=	fftjet-1.3.1
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/fftjet/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/fftjet/
COMMENT=	Multiresolution jet reconstruction in the Fourier domain

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

BUILDLINK_TRANSFORM+=	rm:-fpermissive

PKGCONFIG_OVERRIDE+=	fftjet.pc.in

BUILDLINK_API_DEPENDS.fftw+=	fftw>=3.0
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
