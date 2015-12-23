# $NetBSD$

DISTNAME=	tqdm-3.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tqdm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tqdm/tqdm
COMMENT=	Fast, extensible progress bar for Python
LICENSE=	mit

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
# for UTF-8 in README.md
ALL_ENV+=	LC_CTYPE=en_US.UTF-8
ALL_ENV+=	LC_ALL=en_US.UTF-8
