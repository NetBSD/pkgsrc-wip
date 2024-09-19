# $NetBSD$

DISTNAME=	napalm-iosxr-0.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napalm-automation/}
GITHUB_PROJECT=	napalm-iosxr

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm-iosxr/
COMMENT=	NAPALM module for Cisco IOS-XR
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-napalm-base>=0.18.0:../../wip/py-napalm-base
DEPENDS+=	${PYPKGPREFIX}-IOSXR>=0.20:../../wip/py-IOSXR
DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
