# $NetBSD: Makefile,v 1.1 2014/01/14 21:20:57 jihbed Exp $

DISTNAME=	automata-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/a/automata/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/bniemczyk/automata
COMMENT=	Finite automata for python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/automata-0.1.4

USE_LANGUAGES=	c c++

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
