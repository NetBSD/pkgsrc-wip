# $NetBSD$

DISTNAME=	napalm-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napalm-automation/}
GITHUB_PROJECT=	napalm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm/
COMMENT=	Interact with different router vendors using unified API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-napalm-junos-[0-9]*:../../wip/py-napalm-junos
DEPENDS+=	${PYPKGPREFIX}-napalm-iosxr-[0-9]*:../../wip/py-napalm-iosxr
DEPENDS+=	${PYPKGPREFIX}-napalm-ios-[0-9]*:../../wip/py-napalm-ios
DEPENDS+=	${PYPKGPREFIX}-napalm-eos-[0-9]*:../../wip/py-napalm-eos
DEPENDS+=	${PYPKGPREFIX}-napalm-nxos-[0-9]*:../../wip/py-napalm-nxos

# Not yet packaged:
#DEPENDS+=	${PYPKGPREFIX}-napalm-fortios-[0-9]*:../../wip/py-napalm-fortios
#DEPENDS+=	${PYPKGPREFIX}-napalm-pluribus-[0-9]*:../../wip/py-napalm-pluribus
#DEPENDS+=	${PYPKGPREFIX}-napalm-panos-[0-9]*:../../wip/py-napalm-panos
#DEPENDS+=	${PYPKGPREFIX}-napalm-ros-[0-9]*:../../wip/py-napalm-ros
#DEPENDS+=	${PYPKGPREFIX}-napalm-vyos-[0-9]*:../../wip/py-napalm-vyos

USE_LANGUAGES=	# none

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
