# $NetBSD$

DISTNAME=	SPCM-0.4.1.18
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	b2b0bb5ab846eaa3cd95d213c7d90313235b081b

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

DEPENDS+=	auto-admin>=0.6.3:../../wip/auto-admin

USE_TOOLS+=	bash

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include "../../mk/bsd.pkg.mk"
