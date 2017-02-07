# $NetBSD$

DISTNAME=	tqdm-4.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tqdm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tqdm/tqdm
COMMENT=	Fast, extensible progress bar for Python
LICENSE=	mit

USE_LANGUAGES=	# none

# four test failures as of 4.11.2
# https://github.com/tqdm/tqdm/issues/344
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-mccabe-[0-9]*:../../devel/py-mccabe

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
# for UTF-8 in README.md
ALL_ENV+=	LC_CTYPE=en_US.UTF-8
ALL_ENV+=	LC_ALL=en_US.UTF-8
