# $NetBSD$

DISTNAME=	cluster-admin-0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

NO_BUILD=	yes

DATADIR=	${PREFIX}/share/cluster-admin

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	post-patch
SUBST_FILES.datadir=	${WRKSRC}/CentOS/Sys-scripts/ganglia-web-setup \
			${WRKSRC}/Common/Sys-scripts/slurm-update-idle-nodes
SUBST_SED.datadir=	-e 's|%%DATADIR%%|${PREFIX}/share/cluster-admin|g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	${WRKSRC}/Common/User-scripts/slurm-shell
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

DEPENDS+=		auto-admin>=0.3.8:../../jb-wip/auto-admin

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		PREFIX=${PREFIX} DATADIR=${DATADIR}

.include "../../wip/py-hostlist/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
