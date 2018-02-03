# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	ark-${KAPPSVER}
CATEGORIES=	x11

HOMEPAGE=	http://kde.org/applications/utilities/ark/
COMMENT=	Manages various archive formats within the KDE environment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../wip/kde5/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/ark.categories \
		${PKG_SYSCONFDIR}/xdg/ark.categories

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
