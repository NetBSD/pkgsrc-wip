# $NetBSD$

DISTNAME=	Cython-0.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cython/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/Cython/
COMMENT=	C-Extensions for Python 2.7
LICENSE=	apache-2.0

USE_LANGUAGES+=	c

PYTHON_27_ACCEPTED=		yes
PYTHON_VERSIONS_ACCEPTED=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

post-install:
.for f in cygdb cython cythonize
	cd ${DESTDIR}/${PREFIX}/bin && ${MV} ${f} ${f}-${PYVERSSUFFIX}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
