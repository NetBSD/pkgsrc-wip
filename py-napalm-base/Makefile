# $NetBSD$

DISTNAME=	napalm-base-0.23.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napalm-automation/}
GITHUB_PROJECT=	napalm-base

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm-base/
COMMENT=	Interact with different router vendors using unified API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jtextfsm-[0-9]*:../../wip/py-jtextfsm
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

# Mistakenly installed, prone to name conflicts (e.g. with napalm-iosxr)
post-install:
	rm -f ${DESTDIR}/${PREFIX}/${PYSITELIB}/test/__init__.*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
