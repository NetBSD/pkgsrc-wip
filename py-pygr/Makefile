# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	pygr-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://pygr.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pygr/
COMMENT=	Pygr graph database for bioinformatics
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex

USE_LANGUAGES=	c c++
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-mysqldb, py-pyrex

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
