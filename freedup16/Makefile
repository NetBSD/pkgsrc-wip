# $NetBSD: Makefile,v 1.2 2012/05/29 23:04:07 cheusov Exp $
#

DISTNAME=	freedup-1.6-2-src
PKGNAME=	freedup-1.6
CATEGORIES=	sysutils
MASTER_SITES=	http://freedup.org/
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=    user-destdir

MAINTAINER=	stefano@dragas.it
HOMEPAGE=	http://freedup.org/
COMMENT=	Free disk space by hard linking duplicate files
USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/freedup-1.6
MAKE_ENV+=	BIN_DIR=${PREFIX:Q}/bin
MAKE_ENV+=	MAN_DIR=${PREFIX:Q}/${PKGMANDIR}

DEPENDS+= coreutils>=6.9:../../sysutils/coreutils

SUBST_CLASSES=			fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		freedup.h
SUBST_SED.fix-paths=		-e 's,/usr/bin/,${PREFIX}/bin/g,g'

ONLY_FOR_PLATFORM=DragonFly-*-* \
		NetBSD-[5-9]*-i386 \
		NetBSD-[5-9]*-x86_64 \
		NetBSD-[5-9]*-amd64 

post-extract:
		cd ${WRKSRC} && rm symharden

.include "../../mk/bsd.pkg.mk"
