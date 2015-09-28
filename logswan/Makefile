# $NetBSD$

DISTNAME=	logswan-1.00
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=fcambus/logswan/}
COMMENT=	fast Web log analyzer using probabilistic data structures
LICENSE=	modified-bsd

USE_CMAKE=	yes

SUBST_CLASSES+=		geoip
SUBST_STAGE.geoip=	post-patch
SUBST_FILES.geoip+=	src/logswan.c
SUBST_SED.geoip+=	-e 's,/usr/local,${PREFIX},g'

.include "../../textproc/jansson/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
