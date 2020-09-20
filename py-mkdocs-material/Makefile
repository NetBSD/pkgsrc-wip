# $NetBSD$

DISTNAME=	mkdocs-material-5.5.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/b3/2f/c87b86610caf65d4fe12a033d890be26600d5bdd34132801abd717bee7df/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://squidfunk.github.io/mkdocs-material/
COMMENT=	Material Design theme for MkDocs
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-mkdocs>=1.1:../../textproc/py-mkdocs
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.1.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-pymdown-extensions>=8.0:../../wip/py-pymdown-extensions
DEPENDS+=	${PYPKGPREFIX}-mkdocs-material-extensions>=1.0:../../wip/py-mkdocs-material-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
