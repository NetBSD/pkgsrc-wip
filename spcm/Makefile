# $NetBSD$

DISTNAME=	spcm-0.4.2.15
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_PROJECT=	SPCM
GITHUB_TAG=	0e2e59f4cd251b9956a89cc5db02f07edc3db17a

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

DEPENDS+=	auto-admin>=0.6.7.11:../../wip/auto-admin

USE_TOOLS+=	bash

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include "../../mk/bsd.pkg.mk"
