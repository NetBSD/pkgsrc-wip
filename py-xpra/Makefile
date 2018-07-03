# $NetBSD$

DISTNAME=	xpra-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xpra.org/
COMMENT=	screen(1) for X
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-cython>=0.14:../../devel/py-cython
#DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

REPLACE_PYTHON+=	cups/xpraforwarder
REPLACE_PYTHON+=	*/*.py
REPLACE_PYTHON+=	*/*/*.py
REPLACE_PYTHON+=	*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*.py

INSTALLATION_DIRS+=	share/examples/py-xpra
OWN_DIRS+=		${PKG_SYSCONFDIR}/xpra
CONF_FILES+=		share/examples/py-xpra/xorg.conf ${PKG_SYSCONFDIR}/xpra/xorg.conf
CONF_FILES+=		share/examples/py-xpra/xpra.conf ${PKG_SYSCONFDIR}/xpra/xpra.conf

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing man page installation path.

post-install:
	cd ${DESTDIR}${PREFIX}/etc/xpra && \
		mv xorg.conf xpra.conf ${DESTDIR}${PREFIX}/share/examples/py-xpra

.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
#.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
