# $NetBSD$

DISTNAME=	Cuba-4.2
PKGNAME=	lib${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	http://www.feynarts.de/cuba/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.feynarts.de/cuba/
COMMENT=	Library for multidimensional numerical integration
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=	--with-maxcomp=4
CONFIGURE_ARGS+=	--with-maxdim=32


.include "../../mk/bsd.pkg.mk"
