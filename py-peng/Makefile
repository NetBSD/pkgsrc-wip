# $NetBSD$

DISTNAME=	peng-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/peng/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pmacosta/peng/
COMMENT=	This package provides engineering-related classes and functions
LICENSE=	mit

USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run
REPLACE_BASH+=		sbin/*.sh
REPLACE_PYTHON+=	docs/support/*.py
REPLACE_PYTHON+=	sbin/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
