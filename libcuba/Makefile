# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:38 asau Exp $
#

DISTNAME=	Cuba-2.1
PKGNAME=	lib${DISTNAME:S/C/c/}
CATEGORIES=	math
MASTER_SITES=	http://www.feynarts.de/cuba/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.feynarts.de/cuba/
COMMENT=	Library for multidimensional numerical integration
LICENSE= 	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=	--with-maxcomp=4
CONFIGURE_ARGS+=	--with-maxdim=32

INSTALLATION_DIRS=	share/doc/libcuba

post-install:
	${INSTALL_DATA} ${WRKSRC}/cuba.pdf ${DESTDIR}${PREFIX}/share/doc/libcuba

.include "../../mk/bsd.pkg.mk"
