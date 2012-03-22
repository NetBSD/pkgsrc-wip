# $NetBSD: Makefile,v 1.1.1.2 2012/03/22 19:26:19 outpaddling Exp $
#

DISTNAME=	alberta-2.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.alberta-fem.de/Downloads/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://www.alberta-fem.de/Downloads/
COMMENT=	Adaptive hierarchical finite element toolbox
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran
USE_X11BASE=	yes

.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
