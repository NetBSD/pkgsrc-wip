# $NetBSD$

DISTNAME=	zino-2.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uninett/}
GITHUB_PROJECT=	zino

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Uninett/zino
COMMENT=	Interface-centric (+eBGP++) multi-user SNMP-based network monitor
LICENSE=	apache-2.0

.include "../../lang/python/pyversion.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.1:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-apscheduler>=3.11:../../wip/py-apscheduler
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.11:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-snmp5024>=5.0.24:../../wip/py-snmp5024
DEPENDS+=	${PYPKGPREFIX}-aiodns-[0-9]*:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-netsnmp-cffi>=0.1.1nb1:../../wip/py-netsnmp-cffi
.if ${PYTHON_VERSION} >= 312
DEPENDS+=	${PYPKGPREFIX}-pyasyncore-[0-9]*:../../devel/py-pyasyncore
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

# Needs python >= 39
PYTHON_VERSIONS_INCOMPATIBLE+=	27

# Workaround for using github tarball:
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
