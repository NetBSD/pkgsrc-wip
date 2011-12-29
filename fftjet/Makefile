# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:47:00 jihbed Exp $
#

DISTNAME=	fftjet-1.3.1
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/fftjet/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/fftjet/
COMMENT=	Multiresolution jet reconstruction in the Fourier domain

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

BUILDLINK_TRANSFORM+=    rm:-fpermissive

PKGCONFIG_OVERRIDE+=	fftjet.pc.in

BUILDLINK_API_DEPENDS.fftw+=	fftw>=3.0
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
