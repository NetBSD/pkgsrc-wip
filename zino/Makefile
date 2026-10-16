# $NetBSD$

DISTNAME=	zino-2.5.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uninett/}
GITHUB_PROJECT=	zino

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Uninett/zino
COMMENT=	Interface-centric (+eBGP++) multi-user SNMP-based network monitor
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.1:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-apscheduler>=3.11:../../wip/py-apscheduler
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.11:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-snmp>=6.2.6<7:../../wip/py-snmp
DEPENDS+=	${PYPKGPREFIX}-aiodns>=3.6.1:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-netsnmp-cffi>=0.2.1:../../wip/py-netsnmp-cffi
DEPENDS+=	${PYPKGPREFIX}-pyasyncore>=0:../../devel/py-pyasyncore

# Workaround for using github tarball:
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
