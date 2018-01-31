# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kdebugsettings-${KAPPSVER}
CATEGORIES=	devel

HOMEPAGE=	https://utils.kde.org/
COMMENT=	Application to enable/disable qCDebug
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/applications.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kde.categories \
		${PKG_SYSCONFDIR}/xdg/kde.categories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kde.renamecategories \
		${PKG_SYSCONFDIR}/xdg/kde.renamecategories

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../sysutils/kdbusaddons/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
