# $NetBSD: Makefile,v 1.1.1.1 2007/10/20 15:32:11 noud4 Exp $
#

DISTNAME=	mtd-utils-1.0.0
CATEGORIES=	wip
MASTER_SITES=	ftp://ftp.infradead.org/pub/mtd-utils/

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://www.linux-mtd.infradead.org/
COMMENT=	Memory Technology Device Tools

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
#CFLAGS+=	-D_NETBSD_SOURCE

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

pre-build:
	cp ${FILESDIR}/include/mtd_swab.h ${WRKSRC}/include

post-build:
	cd ${WRKSRC}/checkfs && ${MAKE}
	cd ${WRKSRC}/jittertest && ${MAKE}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkfs/checkfs ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/jittertest/JitterTest ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/jittertest/plotJittervsFill ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
