# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:28 asau Exp $
#

DISTNAME=	pytkgen-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pytkgen/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/tmetsch/pytkgen
COMMENT=	Create Tkinter GUIs from JSON definition files
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson

WRKSRC=		${WRKDIR}/pytkgen-1.4

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
