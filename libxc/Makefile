# $NetBSD: Makefile,v 1.5 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=	libxc-6.2.2
CATEGORIES=	math

MASTER_SITES=	http://www.tddft.org/programs/libxc/down.php?file=${PKGVERSION}/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.tddft.org/programs/libxc/
COMMENT=	Libxc is the ETSF library of exchange-correlation functionals
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c fortran

PKGCONFIG_OVERRIDE+= \
	build/libxc.pc.in \
	lib/pkgconfig/libxcf03.pc \
	lib/pkgconfig/libxcf90.pc

.include "../../mk/bsd.pkg.mk"
