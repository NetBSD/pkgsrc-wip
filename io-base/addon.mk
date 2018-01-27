# $NetBSD: addon.mk,v 1.5 2012/09/30 05:34:21 asau Exp $

.include "../../wip/io-base/version.mk"

SUBST_CLASSES+=			disable-addons
SUBST_STAGE.disable-addons=	pre-configure
SUBST_MESSAGE.disable-addons=	Disabling all addons
SUBST_FILES.disable-addons=	addons/CMakeLists.txt
SUBST_SED.disable-addons=	-e 's,^add_subdirectory(,\# pkgsrc_disabled &,g'

SUBST_CLASSES+=			enable-addon
SUBST_STAGE.enable-addon=	pre-configure
SUBST_MESSAGE.enable-addon=	Enabling ${ADDON_NAME} addon
SUBST_FILES.enable-addon=	addons/CMakeLists.txt
SUBST_SED.enable-addon=		-e 's,^\# pkgsrc_disabled add_subdirectory(${ADDON_NAME}),add_subdirectory(${ADDON_NAME}),g'
.for i in ${ADDON_DEPENDS_ON_ADDONS}
SUBST_SED.enable-addon+=	-e 's,^\# pkgsrc_disabled add_subdirectory(${i}),add_subdirectory(${i}),g'
.endfor

pre-build:
	cd ${WRKSRC}/addons/${ADDON_NAME} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/io ${WRKSRC}/addons/generate.io ${WRKSRC}/addons ${ADDON_NAME}

BUILD_DIRS+=	addons/${ADDON_NAME}
INSTALL_DIRS+=	addons/${ADDON_NAME}

.include "../../wip/io-vm/buildlink3.mk"
.for i in ${ADDON_DEPENDS_ON_ADDONS}
.include "../../wip/io-${i:tl}/buildlink3.mk"
.endfor
