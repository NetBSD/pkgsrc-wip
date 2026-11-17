# $NetBSD$

DISTNAME=	python-status-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python/http/}
CATEGORIES=	www
MASTER_SITES=	https://files.pythonhosted.org/packages/fc/9d/c008b9ade09984a6b5cecce7a4f113b4fbda11a7ccace34770085cb8fd12/
#GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
#FETCH_USING?=	curl

#WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/DanielOaks/http_status
COMMENT=	Simple HTTP status code/description library
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# Workaround for using github tarball:
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
