# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kget-${KAPPSVER}
CATEGORIES=	net

HOMEPAGE=	https://kde.org/applications/internet/kget/
COMMENT=	download manager for KDE
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	pkg-config msgmerge

REPLACE_PERL+=	conf/kget_sensitive.pl conf/kget_limitdownloads.pl

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../security/qgpgme/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../wip/plasma-workspace/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
