# $NetBSD$

DISTNAME=	plantri50
PKGNAME=	plantri-5.0
CATEGORIES=	math
MASTER_SITES=	http://users.cecs.anu.edu.au/~bdm/plantri/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://users.cecs.anu.edu.au/~bdm/plantri/
COMMENT=	Plantri programs for generation of certain types of planar graph
#LICENSE=	# TODO: (see mk/license.mk)

MAKE_FILE=	makefile
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plantri ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fullgen ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
