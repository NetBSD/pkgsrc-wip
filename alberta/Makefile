# $NetBSD: Makefile,v 1.2 2012/03/23 14:06:28 outpaddling Exp $
#

DISTNAME=	alberta-2.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.alberta-fem.de/Downloads/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.alberta-fem.de/
COMMENT=	Adaptive hierarchical finite element toolbox
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
