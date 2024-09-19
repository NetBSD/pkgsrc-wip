# $NetBSD$

DISTNAME=	napalm-junos-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napalm-automation/}
GITHUB_PROJECT=	napalm-junos

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm-junos/
COMMENT=	NAPALM module for JunOS
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-junos-eznc-[0-9]*:../../net/py-junos-eznc
DEPENDS+=	${PYPKGPREFIX}-napalm-base>=0.23.0:../../wip/py-napalm-base

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
