# $NetBSD$

DISTNAME=	identify-2.5.36
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/identify/}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://github.com/chriskuehl/identify
COMMENT=	File identification library for Python
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} identify-cli identify-cli-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
