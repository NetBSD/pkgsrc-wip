# $NetBSD$

PKGNAME=	dps8m-${VER}
DISTNAME=	dps8_R${VER}_source
CATEGORIES=	emulators
MASTER_SITES=	http://ringzero.wikidot.com/local--files/start/
EXTRACT_SUFX=	.tgz

VER=		2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/dps8m/dps8m
COMMENT=	Multics DPS8/M emulator
LICENSE=	# icu

WRKSRC=	${WRKDIR}/${PKGBASE}-code

USE_TOOLS+=	gmake

LDFLAGS.NetBSD+=     -lm

.include "../../devel/libuv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
