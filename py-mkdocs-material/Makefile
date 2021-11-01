# $NetBSD$

DISTNAME=	mkdocs-material-5.5.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mkdocs-material/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://squidfunk.github.io/mkdocs-material/
COMMENT=	Material Design theme for MkDocs
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-mkdocs>=1.1:../../textproc/py-mkdocs
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pymdown-extensions>=8.0:../../wip/py-pymdown-extensions
DEPENDS+=	${PYPKGPREFIX}-mkdocs-material-extensions>=1.0:../../wip/py-mkdocs-material-extensions

PYTHON_VERSIONED_DEPENDENCIES+=	markdown

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
