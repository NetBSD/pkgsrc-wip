# $NetBSD: Makefile,v 1.1.1.1 2009/03/22 22:29:47 jihbed Exp $
#

DISTNAME=	python-aspects-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.tut.fi/~ask/aspects/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.cs.tut.fi/~ask/aspects/index.shtml
COMMENT=	Lightweight aspect oriented programming library for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
