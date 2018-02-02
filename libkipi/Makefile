# $NetBSD: Makefile,v 1.69 2017/12/08 08:52:58 maya Exp $

DISTNAME=	libkipi-${KAPPSVER}
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	KDE image plugin interface
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../wip/kde5/applications.mk"

USE_TOOLS+=	pkg-config

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/tests/plugins/CMakeFiles/kipiplugin_kxmlhelloworld_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/libkexiv2/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
