# $NetBSD: Makefile,v 1.1.1.1 2012/01/24 21:32:21 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pytkgen-1.4

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
