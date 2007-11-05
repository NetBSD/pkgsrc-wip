# $NetBSD: Makefile,v 1.1 2007/11/05 00:25:10 asau Exp $
#

DISTNAME=	chicken-2.732
CATEGORIES=	lang
MASTER_SITES=	http://chicken.wiki.br/dev-snapshots/2007/11/04/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.call-with-current-continuation.org/chicken.html
COMMENT=	Scheme to C compiler, handling R5RS

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake makeinfo
USE_LIBTOOL=	yes
UNLIMIT_RESOURCES=	datasize

# Avoid an ICE in gcc2 on sparc64
#CONFIGURE_ENV+=	F77=${FALSE:Q}

OWN_DIRS+=	${PREFIX}/lib/chicken
OWN_DIRS+=	${PREFIX}/lib/chicken/3

MAKE_VARS=	PLATFORM=bsd PREFIX=${PREFIX:Q} DESTDIR=${DESTDIR:Q}${PREFIX:Q}
MAKE_VARS+=	MANDIR=${DESTDIR:Q}${PREFIX:Q}/man/man1

do-build:
	cd ${WRKSRC:Q} && ${MAKE_PROGRAM} ${MAKE_VARS}
post-build:
	cd ${WRKSRC:Q} && ${MAKE_PROGRAM} ${MAKE_VARS} chicken.info
do-install:
	cd ${WRKSRC:Q} && ${MAKE_PROGRAM} ${MAKE_VARS} install

.include "../../mk/bsd.pkg.mk"
