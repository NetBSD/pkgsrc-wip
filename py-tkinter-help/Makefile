# $NetBSD: Makefile,v 1.1.1.1 2012/01/24 21:29:24 jihbed Exp $
#

DISTNAME=	tkinter.help-2.0
PKGNAME=	${PYPKGPREFIX}-tkinter-help-2.0
CATEGORIES=	x11 python
MASTER_SITES=	http://pypi.python.org/packages/source/t/tkinter.help/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://daemon-tuts.de/
COMMENT=	Small Preview of Tkinter Widgets
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,können,konnen,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
