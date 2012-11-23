# $NetBSD: Makefile,v 1.3 2012/11/23 22:44:44 othyro Exp $
#

DISTNAME=	guppy-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/g/guppy/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://guppy-pe.sourceforge.net/
COMMENT=	Guppy-PE -- A Python Programming Environment
LICENSE=	mit

WRKSRC=	${WRKDIR}/guppy-0.1.9
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
