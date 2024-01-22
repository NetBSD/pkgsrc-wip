# $NetBSD$

GITHUB_PROJECT=	paho.mqtt.python
GITHUB_TAG=	refs/tags/v2.0.0rc2
DISTNAME=	v2.0.0rc2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=eclipse/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.eclipse.org/paho/
COMMENT=	MQTT version 3.1.1 client class
LICENSE=	epl-v1.0

WRKSRC=		${WRKDIR}/paho.mqtt.python-2.0.0rc2
USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
