# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kcontacts-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Address book API for KDE
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kcontacts.categories \
		${PKG_SYSCONFDIR}/xdg/kcontacts.categories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kcontacts.renamecategories \
		${PKG_SYSCONFDIR}/xdg/kcontacts.renamecategories

.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
