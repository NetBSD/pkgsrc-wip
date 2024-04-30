# $NetBSD: Makefile,v 1.197 2020/05/06 14:04:16 adam Exp $

DISTNAME=	amarok-3.0.0
CATEGORIES=	audio multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=amarok/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://amarok.kde.org/
COMMENT=	KDE4 audio player
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules>=0:../../devel/extra-cmake-modules
DEPENDS+=	phonon-qt5-backend-gstreamer>=4.6.3:../../multimedia/phonon-qt5-backend-gstreamer


USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config perl:run

REPLACE_PERL+=	src/kconf_update/amarok-2.4.1-tokens_syntax_update.pl

MYSQL_VERSIONS_ACCEPTED=	mariadb1011 mariadb106 mariadb105 mariadb104

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

CONF_FILES+=	share/examples/amarok/xdg/amarok_homerc ${PKG_SYSCONFDIR}/xdg/amarok_homerc
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg

INSTALLATION_DIRS+=	share/examples/amarok/xdg

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/amarok_homerc ${DESTDIR}${PREFIX}/share/examples/amarok/xdg

.include "../../archivers/karchive/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/kcrash/buildlink3.mk"
.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../devel/kdoctools/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/kpackage/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../misc/attica-qt5/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kdbusaddons/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/kglobalaccel/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
