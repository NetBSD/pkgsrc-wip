# $NetBSD$

DISTNAME=	netmiko-v1.4.0
EGG_NAME=	netmiko-1.4.0
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	sysutils net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ktbyers/}
GITHUB_PROJECT=	netmiko

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ktbyers/netmiko
COMMENT=	Multi-vendor library to simplify Paramiko use
LICENSE=	mit

WRKSRC=         ${WRKDIR}/${EGG_NAME}
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}

DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.13.0:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-scp>=0.10.0:../../wip/py-scp
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYDISTUTILSPKG=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
