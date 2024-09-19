# $NetBSD$

DISTNAME=	py-IOSXR-0.41
PKGNAME=	${DISTNAME:S/py-/${PYPKGPREFIX}-/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fooelisa/}
GITHUB_PROJECT=	pyIOSXR
EGG_NAME=	${DISTNAME:S/-//}

WRKSRC=		${WRKDIR}/${DISTNAME:S/-//:tl}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fooelisa/pyiosxr
COMMENT=	Library for interacting with IOS-XR routers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-netmiko>=0.5.2:../../wip/py-netmiko
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.4:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
