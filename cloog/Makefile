# $NetBSD: Makefile,v 1.6 2015/02/15 20:24:56 jihbed Exp $

DISTNAME=	cloog-0.18.3
CATEGORIES=	math
MASTER_SITES=	http://www.bastoul.net/cloog/pages/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.cloog.org/
COMMENT=	The CLooG Code Generator in the Polyhedral Model's Home
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
