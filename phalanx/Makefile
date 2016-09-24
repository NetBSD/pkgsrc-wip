# $NetBSD: Makefile,v 1.1 2015/05/06 21:50:36 f8l Exp $

PHALANX_VER=		25
PHALANX_VER_ROMAN=	XXV

DISTNAME=	phalanx-${PHALANX_VER_ROMAN}-source
PKGNAME=	phalanx-${PHALANX_VER}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phalanx/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/phalanx/
COMMENT=	Xboard/Winboard compatible chess engine
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/Phalanx-${PHALANX_VER_ROMAN}
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
ALL_ENV+=	prefix=${PREFIX}
MAKE_ENV+=	DEFINES=${DEFINES:Q}
DEFINES+=	-DGNUFUN
DEFINES+=	-DLEARN_DIR=\"${VARBASE:Q}/games\"
BUILD_TARGET=	phalanx
BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.pkg.mk"
