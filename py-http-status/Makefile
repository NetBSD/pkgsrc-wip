# $NetBSD$

DISTNAME=	http_status-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=DanielOaks/}
GITHUB_PROJECT=	http_status
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
FETCH_USING=	curl

WRKSRC=		${WRKDIR}/${DISTNAME}

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
