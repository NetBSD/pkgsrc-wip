# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kservice-${KF5VER}
CATEGORIES=	devel

HOMEPAGE=	https://projects.kde.org/projects/frameworks/kservice
COMMENT=	Advanced plugin and service introspection
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../wip/kdoctools

USE_TOOLS+=	msgmerge

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/kservice/applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/applications.menu

.include "../../lang/python/tool.mk"
.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kcrash/buildlink3.mk"
.include "../../wip/kdbusaddons/buildlink3.mk"
.include "../../wip/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
