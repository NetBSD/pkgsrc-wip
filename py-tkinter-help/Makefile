# $NetBSD: Makefile,v 1.3 2013/06/04 07:45:24 thomasklausner Exp $
#

DISTNAME=	tkinter.help-2.0
PKGNAME=	${PYPKGPREFIX}-tkinter-help-2.0
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tkinter.help/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://daemon-tuts.de/
COMMENT=	Small Preview of Tkinter Widgets
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,können,konnen,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
