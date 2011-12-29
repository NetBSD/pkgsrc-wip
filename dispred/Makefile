# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:28:17 jihbed Exp $
#

DISTNAME=	DISPred-2.0
PKGNAME=	dispred-2.0
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/dispred/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.hepforge.org/archive/dispred/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++ fortran

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
