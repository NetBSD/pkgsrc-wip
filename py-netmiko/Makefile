# $NetBSD$

DISTNAME=	netmiko-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils net
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netmiko/}
GITHUB_PROJECT=	netmiko

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ktbyers/netmiko
COMMENT=	Multi-vendor library to simplify Paramiko use
LICENSE=	mit

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}

#DEPENDS+=	${PYPKGPREFIX}-ntc-templates>=2.9.5:../../wip/py-ntc-templates

DEPENDS+=	${PYPKGPREFIX}-paramiko>=2.9.5:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-serial>=3.3:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-scp>=0.13.6:../../net/py-scp
DEPENDS+=	${PYPKGPREFIX}-textfsm>=1.1.3:../../textproc/py-textfsm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
