# $NetBSD$

DISTNAME=	virtualenv-20.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://virtualenv.pypa.io/
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

CONFLICTS+=	${PYPKGPREFIX}-virtualenv-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-distlib>=0.3.1<1:../../wip/py-distlib
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.2.0<4:../../wip/py-filelock
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2<3:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0<2:../../lang/py-six
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=0.12:../../devel/py-importlib-metadata
.endif
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-pathlib2>=2.3.3<3:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.0:../../devel/py-importlib-resources
.endif

USE_LANGUAGES=	# none

REPLACE_PYTHON=	virtualenv.py

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools_scm:build

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} virtualenv virtualenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
