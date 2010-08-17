# $NetBSD: Makefile,v 1.1.1.1 2010/08/17 12:12:34 jihbed Exp $
#

DISTNAME=	guppy-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/g/guppy/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://guppy-pe.sourceforge.net/
COMMENT=	Guppy-PE -- A Python Programming Environment
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/guppy-0.1.9
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
