# $NetBSD$

DISTNAME=	cluster-admin-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://outpaddling.mooo.com/~bacon/Acadix/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	HPC cluster admin tools
LICENSE=	2-clause-bsd

# Add py-hostlist dep

DATADIR=	${PREFIX}/share/cluster-admin

SUBST_CLASSES+=		sbin
SUBST_STAGE.sbin=	pre-configure
SUBST_FILES.sbin+=	Common/Src/cluster-passwd.c
SUBST_SED.sbin=		-e 's|/usr/local/sbin|${PREFIX}/sbin|g'

DEPENDS+=	auto-admin>=0.4.9:../../uwm-pkgsrc-wip/auto-admin

USE_TOOLS+=	bash

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	PREFIX=${PREFIX} DATADIR=${DATADIR}

.include "../../mk/bsd.pkg.mk"
