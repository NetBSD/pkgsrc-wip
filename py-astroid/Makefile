# $NetBSD: Makefile,v 1.2 2013/11/14 13:24:32 szptvlfn Exp $

DISTNAME=	astroid-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/a/astroid/
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://bitbucket.org/logilab/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../devel/py-logilab-common/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
