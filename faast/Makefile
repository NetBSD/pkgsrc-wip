# $NetBSD: Makefile,v 1.1.1.1 2012/01/01 15:11:20 jihbed Exp $
#

DISTNAME=	faast-0.2.0
CATEGORIES=	math
MASTER_SITES=	http://www.lix.polytechnique.fr/~defeo/FAAST/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.lix.polytechnique.fr/~defeo/FAAST
COMMENT= Library for Fast Arithmetics in Artin-Schreier Towers
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES=	c c++

.include "../../math/ntl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
