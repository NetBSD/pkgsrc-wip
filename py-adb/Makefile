# $NetBSD: Makefile,v 1.1 2017/04/14 12:10:26 leot Exp $

DISTNAME=	adb-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/adb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/python-adb
COMMENT=	Pure Python implementation of the Android ADB and Fastboot protocols
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-m2crypto>=0.21.1:../../security/py-m2crypto
DEPENDS+=	${PYPKGPREFIX}-libusb1>=1.0.16:../../wip/py-libusb1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
