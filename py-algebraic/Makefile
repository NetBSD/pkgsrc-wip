# $NetBSD: Makefile,v 1.4 2015/02/08 22:11:58 jihbed Exp $

VERSION=	0.3.1.dev-20120112
DISTNAME=	python-algebraic-0.3.1.dev-20120112
EGG_NAME=	python_algebraic-0.3.1.dev20120112
PKGNAME=	${PYPKGPREFIX}-algebraic-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-algebraic/}
EXTRACT_SUFX=	.zip#md5=cbf55e6cefe57b36cdb962a2d5926a45

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/python-algebraic/
COMMENT=	Algebraic modeling system for Python
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PLIST_SUBST+=		EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
