# $NetBSD: Makefile,v 1.69 2017/12/08 08:52:58 maya Exp $

DISTNAME=	kgpg-${KAPPSVER}
CATEGORIES=	security

HOMEPAGE=	https://kde.org/applications/utilities/kgpg/
COMMENT=	KDE encryption tool
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{AUTOSTART_INSTALL_DIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/org.kde.kgpg.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.kde.kgpg.desktop

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/akonadi-contacts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
