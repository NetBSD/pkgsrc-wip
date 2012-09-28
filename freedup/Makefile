# $NetBSD: Makefile,v 1.5 2012/09/28 23:21:49 asau Exp $
#

DISTNAME=	freedup-1.3-1-src
PKGNAME=	freedup-1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://freedup.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hallmann@ahatec.de
HOMEPAGE=	http://freedup.org/
COMMENT=	Free disk space by hard linking duplicate files.

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/freedup-1.3
MAKE_ENV+=	BIN_DIR=${PREFIX:Q}/bin
MAKE_ENV+=	MAN_DIR=${PREFIX:Q}/${PKGMANDIR}

DEPENDS+= coreutils>=6.9:../../sysutils/coreutils

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths+=	pre-configure
SUBST_MESSAGE.fix-paths+=	Fixing absolute paths.
SUBST_FILES.fix-paths=		freedup.h
SUBST_SED.fix-paths=		-e 's,/usr/bin/,${PREFIX}/bin/g,g'

.include "../../mk/bsd.pkg.mk"
