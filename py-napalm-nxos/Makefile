# $NetBSD$

DISTNAME=	napalm-nxos-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napalm-automation/}
GITHUB_PROJECT=	napalm-nxos

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm-nxos
COMMENT=	NAPALM module for Cisco IOS
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-napalm-base>=0.18.0:../../wip/py-napalm-base
DEPENDS+=	${PYPKGPREFIX}-nxos-[0-9]*:../../wip/py-nxos
DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-scp-[0-9]*:../../net/py-scp

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
