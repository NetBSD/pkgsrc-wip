# $NetBSD$

DISTNAME=	napalm-eos-0.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napalm-automation/}
GITHUB_PROJECT=	napalm-eos

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm-eos
COMMENT=	NAPALM module for Arista EOS
LICENSE=	apache-2.0

EXTRACT_USING=	gtar

DEPENDS+=	${PYPKGPREFIX}-napalm-base>=0.23.0:../../wip/py-napalm-base
DEPENDS+=	${PYPKGPREFIX}-eapi-[0-9]*:../../wip/py-eapi

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
