# $NetBSD$

DISTNAME=	nodeenv-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ekalinin/}
GITHUB_PROJECT=	nodeenv
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://ekalinin.github.io/nodeenv/
COMMENT=	Node.js virtual environment
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TOOL_DEPENDS+= 	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

REPLACE_PYTHON=	nodeenv.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} nodeenv nodeenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
