# $NetBSD$

DISTNAME=	pymdown-extensions-8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymdown-extensions/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/facelessuser/pymdown-extensions
COMMENT=	Extension pack for Python Markdown
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES+=	markdown

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
