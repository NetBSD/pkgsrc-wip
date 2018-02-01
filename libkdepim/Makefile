# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	libkdepim-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Libraries for KDE PIM applications
LICENSE=	gnu-lgpl-v2

.include "../../wip/kde5/applications.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/libkdepim.categories \
		${PKG_SYSCONFDIR}/xdg/libkdepim.categories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/libkdepim.renamecategories \
		${PKG_SYSCONFDIR}/xdg/libkdepim.renamecategories

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/akonadi-contacts/buildlink3.mk"
.include "../../wip/akonadi-search/buildlink3.mk"
.include "../../wip/kldap/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
