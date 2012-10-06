# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:28 asau Exp $
#

DISTNAME=	Aesthete-0.4.1-7
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-aesthete-0.4.1-7
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/A/Aesthete/

MAINTAINER= 	jihbed.research@gmail.com
HOMEPAGE=       http://www.philtweir.co.uk/aesthete/wiki/pmwiki.php
COMMENT=	Integrated mathematics environment
LICENSE=	gnu-gpl-v3

DEPENDS+=	linux-libertine-ttf>=5.1.3:../../fonts/linux-libertine-ttf
DEPENDS+=	${PYPKGPREFIX}-argparse>=1.1:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.6.7:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.6:../../textproc/py-lxml

WRKSRC=		${WRKDIR}/Aesthete-0.4.1-7

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/aesthete_ime ${WRKSRC}/bin/aesthete_ime${PYVERSSUFFIX}

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
