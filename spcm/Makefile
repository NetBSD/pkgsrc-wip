# $NetBSD$

DISTNAME=	SPCM-0.4.1.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	b160c15c75a001bfa68e2631a2f04dc765bec25b

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/spcm.php
COMMENT=	Simple, portable cluster management
LICENSE=	2-clause-bsd

# Add py-hostlist dep

DATADIR=	${PREFIX}/share/cluster-admin

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	pre-configure
SUBST_FILES.datadir=	${WRKSRC}/CentOS/Sys-scripts/ganglia-web-setup \
			${WRKSRC}/Common/Sys-scripts/slurm-update-idle-nodes
SUBST_SED.datadir=	-e 's|%%DATADIR%%|${PREFIX}/share/cluster-admin|g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	${WRKSRC}/Common/User-scripts/slurm-shell
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

SUBST_CLASSES+=		sbin
SUBST_STAGE.sbin=	pre-configure
SUBST_FILES.sbin+=	${WRKSRC}/Common/Src/cluster-passwd.c
SUBST_SED.sbin=		-e 's|/usr/local/sbin|${PREFIX}/sbin|g'

DEPENDS+=	auto-admin>=0.6.3:../../wip/auto-admin

USE_TOOLS+=	bash

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include "../../mk/bsd.pkg.mk"
