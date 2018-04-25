# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kcalutils-${KAPPSVER}
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	KDE calendar access library
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kcalutils.categories \
		${PKG_SYSCONFDIR}/xdg/kcalutils.categories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kcalutils.renamecategories \
		${PKG_SYSCONFDIR}/xdg/kcalutils.renamecategories

.include "../../wip/kcalcore/buildlink3.mk"
.include "../../wip/kidentitymanagement/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
