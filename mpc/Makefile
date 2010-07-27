# $NetBSD: Makefile,v 1.5 2010/07/27 11:06:36 asau Exp $
#

DISTNAME=	mpc-0.8.2
PKGNAME=	mpcomplex-0.8.2
CATEGORIES=	math devel
MASTER_SITES=	http://www.multiprecision.org/mpc/download/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://www.multiprecision.org/mpc/
COMMENT=	Arithmetic of complex numbers with arbitrarily high precision
LICENSE=	gnu-lgpl-v2.1
PKG_DESTDIR_SUPPORT= user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	check

INFO_FILES=	YES

.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
