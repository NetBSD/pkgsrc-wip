# $NetBSD: Makefile,v 1.4 2013/06/04 07:45:23 thomasklausner Exp $

DISTNAME=	guppy-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guppy/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://guppy-pe.sourceforge.net/
COMMENT=	Guppy-PE -- A Python Programming Environment
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

WRKSRC=		${WRKDIR}/guppy-0.1.9
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
