# $NetBSD: Makefile,v 1.3 2013/06/04 07:45:23 thomasklausner Exp $

DISTNAME=	pytkgen-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytkgen/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/tmetsch/pytkgen
COMMENT=	Create Tkinter GUIs from JSON definition files
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

WRKSRC=		${WRKDIR}/pytkgen-1.4

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
