# $NetBSD: Makefile,v 1.5 2011/12/28 23:52:22 jihbed Exp $
#

DISTNAME=	greenlet-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/g/greenlet/
EXTRACT_SUFX=	.zip#md5=96b99f659d466ce1c5b3d72bc25dddac

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://undefined.org/python/#greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_VERSIONS_ACCEPTED= 25 26 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
