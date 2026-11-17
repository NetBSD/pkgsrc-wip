# $NetBSD$

DISTNAME=	argus-api-client-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uninett/}
GITHUB_PROJECT=	pyargus
FETCH_USING?=	curl

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Uninett/pyargus
COMMENT=	Python API to Argus
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/pyargus-${PKGVERSION_NOREV}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-simple-rest-client-[0-9]*:../../wip/py-simple-rest-client
DEPENDS+=	${PYPKGPREFIX}-iso8601-[0-9]*:../../time/py-iso8601

# Workaround for using github tarball:
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
