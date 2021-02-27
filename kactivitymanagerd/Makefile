# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kactivitymanagerd-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	System service to manage user's activities and track the usage patterns
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	msgmerge pkg-config

# generation of virtualdesktopswitch.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/service/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/service/plugins/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
