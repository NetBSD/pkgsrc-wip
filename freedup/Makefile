# $NetBSD: Makefile,v 1.2 2008/01/10 09:20:48 ahallmann Exp $
#

DISTNAME=	freedup-1.3-1-src
PKGNAME=	freedup-1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://freedup.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hallmann@ahatec.de
HOMEPAGE=	http://freedup.org/
COMMENT=	Free disk space by hard linking duplicate files.
USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/freedup-1.3
MAKE_ENV+=	BIN_DIR=${PREFIX:Q}/bin
MAKE_ENV+=	MAN_DIR=${PREFIX:Q}/${PKGMANDIR}

DEPENDS+= coreutils>=6.9:../../sysutils/coreutils

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths+= 	pre-configure
SUBST_MESSAGE.fix-paths+= 	Fixing absolute paths.
SUBST_FILES.fix-paths=		freedup.h
SUBST_SED.fix-paths=		-e 's,/usr/bin/,${PREFIX}/bin/${GNU_PROGRAM_PREFIX:Q},g'

.include "../../mk/bsd.pkg.mk"
