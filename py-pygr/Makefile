# $NetBSD: Makefile,v 1.3 2012/01/30 06:46:59 noud4 Exp $
#

DISTNAME=	pygr-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://pygr.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pygr/
COMMENT=	Pygr graph database for bioinformatics
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=       ${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES= c c++
PYTHON_VERSIONS_ACCEPTED= 27 26 25 24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
