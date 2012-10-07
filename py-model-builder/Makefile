# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:23 asau Exp $
#

DISTNAME=	Model-Builder-0.4.6
EGG_NAME=	Model_Builder-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/M/m/S/B/b/}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/model-builder/model-builder/0.4.6/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://model-builder.sourceforge.net/
COMMENT=	Graphical ODE simulator

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

USE_LANGUAGES=	# none

post-extract:
	${CP} ${FILESDIR}/model-builder.desktop ${WRKSRC}
	${CP} ${FILESDIR}/MB.png ${WRKSRC}


.include "../../lang/python/egg.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
