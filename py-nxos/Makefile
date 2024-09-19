# $NetBSD$

DISTNAME=	pynxos-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=networktocode/}
GITHUB_PROJECT=	pynxos

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/networktocode/pynxos
COMMENT=	Support module for Cisco NX-OS
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
