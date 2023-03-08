# $NetBSD$

DISTNAME=	sbapp-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sbapp/}

MAINTAINER=	gdt@lexort.com
HOMEPAGE=	https://unsigned.io/sideband
COMMENT=	GUI LXMF client for Android, Linux and macOS
LICENSE=	cc-by-nc-sa-v4.0-license

DEPENDS+=	${PYPKGPREFIX}-rns>=0.4.6:../../wip/py-rns
DEPENDS+=	${PYPKGPREFIX}-lxmf>=0.2.8:../../wip/py-lxmf
DEPENDS+=	${PYPKGPREFIX}-kivy>=2.0.0:../../devel/py-kivy #2.1.0
DEPENDS+=	# TODO: plyer>=0
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-qrcode>=6:../../graphics/py-qrcode

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
