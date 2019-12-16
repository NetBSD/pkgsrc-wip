# $NetBSD$

DISTNAME=	pip2pi-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip2pi/}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/wolever/pip2pi/
COMMENT=	Build a PyPI-compatible package repository from pip
LICENSE=	2-clause-bsd

post-install:
.for bins in dir2pi pip2pi pip2tgz
	${MV} ${DESTDIR}${PREFIX}/bin/${bins} ${DESTDIR}${PREFIX}/bin/${bins}-${PYVERSSUFFIX}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
