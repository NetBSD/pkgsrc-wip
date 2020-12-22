# $NetBSD$

DISTNAME=	spcm-0.4.2.24
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_PROJECT=	SPCM
GITHUB_TAG=	e864b60def2225f0df4e39192c63a8d931a3f9ef

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/spcm.php
COMMENT=	Simple, portable cluster management
LICENSE=	2-clause-bsd

# Add py-hostlist dep

DATADIR=	${PREFIX}/share/spcm

SUBST_CLASSES+=		sbin
SUBST_STAGE.sbin=	pre-configure
SUBST_FILES.sbin+=	Common/Src/cluster-passwd.c
SUBST_SED.sbin=		-e 's|%%PREFIX%%|${PREFIX}|g'

DEPENDS+=	auto-admin>=0.6.9.3:../../wip/auto-admin

USE_TOOLS+=	bash

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include "../../mk/bsd.pkg.mk"
