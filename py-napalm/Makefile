# $NetBSD$

DISTNAME=	napalm-0.51.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	-https://github.com/napalm-automation/napalm/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm/
COMMENT=	Interact with different router vendors using unified API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-netmiko-[0-9]*:../../wip/py-netmiko
DEPENDS+=	${PYPKGPREFIX}-IOSXR-[0-9]*:../../wip/py-IOSXR
DEPENDS+=	${PYPKGPREFIX}-junos-eznc-[0-9]*:../../net/py-junos-eznc
DEPENDS+=	${PYPKGPREFIX}-ncclient-[0-9]*:../../net/py-ncclient

# Not yet packaged, this may depend on:
# pyeapi	Library for Arista's eAPI command API implementation
# pyFG		API for FortiOS or how to turn FortiOS into JunOS
# pycsco	Library for working with Cisco NX-OS switches
# bnclient	Blade Network Technologies Netconf Python Client

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSUFFIX=${PYVERSUFFIX}
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PYTHON_VERSIONS_ACCEPTED=	35 34 33 27 26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
