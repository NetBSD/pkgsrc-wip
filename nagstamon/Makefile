# $NetBSD: Makefile,v 1.66 2021/04/21 11:42:27 adam Exp $

DISTNAME=	nagstamon-3.16.2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=HenriWahl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	https://nagstamon.de/
COMMENT=	Nagios status monitor which takes place in systray or on desktop
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-arrow-[0-9]*:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
# right socks?
DEPENDS+=	${PYPKGPREFIX}-python-socks-[0-9]*:../../net/py-python-socks
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-gssapi-[0-9]*:../../security/py-requests-gssapi
DEPENDS+=	${PYPKGPREFIX}-secretstorage-[0-9]*:../../security/py-secretstorage

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	setup.py
SUBST_VARS.manpath=	PKGMANDIR

WRKSRC=		${WRKDIR}/${DISTNAME:S/^n/N/}

.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
