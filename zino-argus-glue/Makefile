# $NetBSD$

DISTNAME=	zino-argus-glue-0.5.1
#PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uninett/}
GITHUB_PROJECT=	zino-argus-glue
FETCH_USING?=	curl

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Uninett/zino-argus-glue
COMMENT=	Glue service interconnecting zino to an Argus instance
LICENSE=	apache-2.0

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-argus-api-client-[0-9]*:../../wip/py-argus-api-client
DEPENDS+=	${PYPKGPREFIX}-snmp>=6.2.6<7:../../wip/py-snmp
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-zinolib>=1.3.4:../../wip/py-zinolib
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.7:../../devel/py-pydantic
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

# Workaround for using github tarball:
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
