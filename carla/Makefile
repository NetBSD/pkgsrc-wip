# $NetBSD$

DISTNAME=	carla-2.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=falkTX/}
GITHUB_PROJECT=	Carla
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kx.studio/Applications:Carla
COMMENT=	Audio plugin host
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

USE_TOOLS+=	gmake pkg-config gsed bash:run
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:M*clang*)
MAKE_FLAGS+=	CLANG=true
.endif

PKGCONFIG_OVERRIDE+=	data/carla-native-plugin.pc
PKGCONFIG_OVERRIDE+=	data/carla-standalone.pc
PKGCONFIG_OVERRIDE+=	data/carla-utils.pc

REPLACE_BASH+=		data/carla
REPLACE_BASH+=		data/carla-control
REPLACE_BASH+=		data/carla-bridge-lv2-modgui
REPLACE_BASH+=		data/carla-database
REPLACE_BASH+=		data/carla-jack-multi
REPLACE_BASH+=		data/carla-jack-patchbayplugin
REPLACE_BASH+=		data/carla-jack-single
REPLACE_BASH+=		data/carla-osc-gui
REPLACE_BASH+=		data/carla-patchbay
REPLACE_BASH+=		data/carla-rack
REPLACE_BASH+=		data/carla-settings

REPLACE_PYTHON+=	data/carla-single
REPLACE_PYTHON+=	source/frontend/carla
REPLACE_PYTHON+=	source/frontend/carla-control
REPLACE_PYTHON+=	source/frontend/carla-jack-multi
REPLACE_PYTHON+=	source/frontend/carla-jack-single
REPLACE_PYTHON+=	source/frontend/carla-patchbay
REPLACE_PYTHON+=	source/frontend/carla-plugin
REPLACE_PYTHON+=	source/frontend/carla-plugin-patchbay
REPLACE_PYTHON+=	source/frontend/carla-rack
REPLACE_PYTHON+=	source/frontend/bigmeter-ui
REPLACE_PYTHON+=	source/frontend/midipattern-ui
REPLACE_PYTHON+=	source/frontend/notes-ui
REPLACE_PYTHON+=	source/frontend/xycontroller-ui

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Correcting the Python executable name.
SUBST_FILES.py+=	data/carla-bridge-lv2-modgui
SUBST_FILES.py+=	data/carla-control
SUBST_FILES.py+=	data/carla-database
SUBST_FILES.py+=	data/carla-jack-multi
SUBST_FILES.py+=	data/carla-jack-single
SUBST_FILES.py+=	data/carla-osc-gui
SUBST_FILES.py+=	data/carla-patchbay
SUBST_FILES.py+=	data/carla-rack
SUBST_FILES.py+=	data/carla-settings
SUBST_SED.py+=		-e "s,python3,${PYTHONBIN},g"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_FILES.prefix+=	source/frontend/carla_shared.py
SUBST_SED.prefix+=	-e "s,/usr/local,${PREFIX},g"

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/carla/carla
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/carla/carla-control
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/carla/carla-jack-multi
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/carla/carla-jack-single
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/carla/carla-patchbay
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/carla/carla-rack

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
.  include "../../x11/gtk3/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.endif
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
