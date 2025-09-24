# $NetBSD$

DISTNAME=	thonny-4.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=thonny/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://thonny.org/
COMMENT=	Python IDE for beginners
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-Send2Trash>=1.5:../../sysutils/py-Send2Trash
DEPENDS+=	${PYPKGPREFIX}-asttokens>=2.0:../../lang/py-asttokens
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.18.1:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-mypy>=0.761:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-pylint>=2.4:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-setuptools>=45.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-Tk>=3:../../x11/py-Tk

USE_PKGLOCALEDIR=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
