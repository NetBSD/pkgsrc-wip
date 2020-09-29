# $NetBSD$

DISTNAME=	pymdown-extensions-8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymdown-extensions/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/facelessuser/pymdown-extensions
COMMENT=	Extension pack for Python Markdown
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-markdown>=3.1.1:../../textproc/py-markdown

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
