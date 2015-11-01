# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	automata-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/a/automata/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/bniemczyk/automata
COMMENT=	Finite automata for python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
