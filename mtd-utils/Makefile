# $NetBSD: Makefile,v 1.5 2014/02/11 21:04:07 noud4 Exp $
#

DISTNAME=	mtd-utils-1.0.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.infradead.org/pub/mtd-utils/
LICENSE=	gnu-gpl-v2

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://www.linux-mtd.infradead.org/
COMMENT=	Memory Technology Device Tools

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
#CFLAGS+=	-D_NETBSD_SOURCE

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	post-patch

pre-build:
	cp ${FILESDIR}/include/mtd_swab.h ${WRKSRC}/include

post-build:
	cd ${WRKSRC}/checkfs && ${MAKE}
	cd ${WRKSRC}/jittertest && ${MAKE}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkfs/checkfs ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/jittertest/JitterTest ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/jittertest/plotJittervsFill ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
