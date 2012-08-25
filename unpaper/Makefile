# $NetBSD: Makefile,v 1.1.1.1 2012/08/25 18:27:06 jihbed Exp $
#

DISTNAME=	unpaper-0.3
CATEGORIES=	textproc
MASTER_SITES=	http://garr.dl.sourceforge.net/project/unpaper.berlios/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://unpaper.berlios.de/
COMMENT=	Post-processing scanned and photocopied book pages
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= bash

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local/bin,${DESTDIR}${PREFIX}/bin,g'
SUBST_FILES.paths+=	make.sh
SUBST_MESSAGE.paths=	Fixing header search paths.

INSTALLATION_DIRS= bin

do-build:
	cd ${WRKSRC}/src; ${CC} ${CFLAGS} -DUNIX -o unpaper unpaper.c -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/unpaper ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
