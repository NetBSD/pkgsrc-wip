# $NetBSD: Makefile,v 1.4 2011/08/12 13:10:08 asau Exp $

DISTNAME=	greenlet-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/g/greenlet/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://undefined.org/python/#greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED= 25 26 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
