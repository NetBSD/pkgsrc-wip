# $NetBSD$

DISTNAME=	spcm-0.5.9.13
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	3d3d33100fe8075f5a5215231a4d9d68e37aa41c

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/SPCM
COMMENT=	Simple, portable cluster management
LICENSE=	2-clause-bsd

# Add py-hostlist dep

DATADIR=	${PREFIX}/share/spcm

SUBST_CLASSES+=		sbin
SUBST_STAGE.sbin=	pre-configure
SUBST_FILES.sbin+=	Common/Src/spcm-passwd.c
SUBST_SED.sbin=		-e 's|%%PREFIX%%|${PREFIX}|g'

DEPENDS+=	auto-admin>=0.8.0.38:../../wip/auto-admin

USE_TOOLS+=	bash

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/SPCM-${GITHUB_TAG}
MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include "../../mk/bsd.pkg.mk"
