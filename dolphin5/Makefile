# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	dolphin-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	http://kde.org/applications/system/dolphin/
COMMENT=	KDE File Manager
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../wip/kde5/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../wip/kdoctools
DEPENDS+=	kio-extras>=${KAPPSVER}:../../wip/kio-extras

REPLACE_RUBY+=	src/settings/services/servicemenuinstallation
REPLACE_RUBY+=	src/settings/services/servicemenudeinstallation

.include "../../lang/ruby/replace.mk"

USE_TOOLS+=	msgmerge

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/servicemenu.knsrc \
		${PKG_SYSCONFDIR}/xdg/servicemenu.knsrc

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/baloo-widgets/buildlink3.mk"
.include "../../wip/kactivities5/buildlink3.mk"
.include "../../wip/kcmutils/buildlink3.mk"
.include "../../wip/knewstuff/buildlink3.mk"
.include "../../wip/kparts/buildlink3.mk"
.include "../../wip/plasma-workspace/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
