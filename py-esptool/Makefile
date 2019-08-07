# $NetBSD$

GITHUB_PROJECT=	esptool
VERSION=	2.7
NBVERSION=
PKGNAME=	${GITHUB_PROJECT}-${VERSION}${NBVERSION}
DISTNAME=	v${VERSION}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=espressif/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/espressif/esptool/
COMMENT=	Firmware tool for ESP8266/ESP32
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
EGG_INFODIR=	${PKGNAME_NOREV}-py${PYVERSSUFFIX}.egg-info

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	espefuse.py
REPLACE_PYTHON+=	espsecure.py
REPLACE_PYTHON+=	esptool.py

DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
