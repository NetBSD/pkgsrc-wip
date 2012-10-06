# $NetBSD: Makefile,v 1.3 2012/10/06 17:13:30 asau Exp $
#

VERSION= 0.3.1.dev-20120112
DISTNAME=	python-algebraic-0.3.1.dev-20120112
EGG_NAME=	python_algebraic-0.3.1.dev_20120112
PKGNAME=	${PYPKGPREFIX}-algebraic-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-algebraic/
EXTRACT_SUFX=	.zip#md5=cbf55e6cefe57b36cdb962a2d5926a45

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/rzoz/python-algebraic
COMMENT=	Algebraic modeling system for Python
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes
PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
