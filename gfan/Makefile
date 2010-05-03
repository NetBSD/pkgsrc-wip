# $NetBSD: Makefile,v 1.1.1.1 2010/05/03 14:57:41 jihbed Exp $
#

GFAN_VERSION=	0.4
DISTNAME=	gfan${GFAN_VERSION}
PKGNAME=	gfan-${GFAN_VERSION}
CATEGORIES=	math
MASTER_SITES=	http://www.math.tu-berlin.de/~jensen/software/gfan/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.tu-berlin.de/~jensen/software/gfan/gfan.html
COMMENT=	Program for computing with Groebner fans
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	Makefile
SUBST_MESSAGE.paths=	Fixing header search paths.

EDGDIR=	${PREFIX}/share/examples/gfan

INSTALLATION_DIRS=	bin ${EDGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gfan ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${EDGDIR}
	

.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/cddlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
