# $NetBSD: Makefile,v 1.5 2013/10/20 20:38:58 bubuchka Exp $

DISTNAME=	pymongo-2.6.3
PKGNAME=	${PYPKGPREFIX}-mongo-2.6.3
CATEGORIES=	databases devel python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pymongo/
FETCH_USING=	curl

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://docs.mongodb.org/ecosystem/drivers/python/
COMMENT=	Python driver for MongoDB
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
