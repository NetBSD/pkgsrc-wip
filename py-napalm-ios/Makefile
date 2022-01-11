# $NetBSD$

DISTNAME=	napalm-ios-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napalm-automation/}
GITHUB_PROJECT=	napalm-ios

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm-ios
COMMENT=	NAPALM module for Cisco IOS
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-napalm-base>=0.23.2:../../wip/py-napalm-base
DEPENDS+=	${PYPKGPREFIX}-netmiko>=1.4.0:../../wip/py-netmiko

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
