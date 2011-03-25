# $NetBSD: Makefile,v 1.1.1.1 2011/03/25 18:43:42 jihbed Exp $
#

DISTNAME=	Cuba-2.1
PKGNAME=	lib${DISTNAME:S/C/c/}
CATEGORIES=	math
MASTER_SITES=	http://www.feynarts.de/cuba/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.feynarts.de/cuba/
COMMENT=	Library for multidimensional numerical integration
LICENSE= 	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

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
