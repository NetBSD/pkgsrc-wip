# $NetBSD: Makefile,v 1.69 2017/12/08 08:52:58 maya Exp $

DISTNAME=	okular-${KAPPSVER}
CATEGORIES=	print

HOMEPAGE=	https://kde.org/applications/graphics/okular/
COMMENT=	KDE universal document viewer
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../wip/kde5/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
#DEPENDS+=	kactivities5>=5.19.0:../../x11/libkactivities5

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/okular.categories \
		${PKG_SYSCONFDIR}/xdg/okular.categories

# generation of kded.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/generators/djvu/CMakeFiles/okularGenerator_djvu_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/generators/chm/CMakeFiles/okularGenerator_chmlib_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/generators/tiff/CMakeFiles/okularGenerator_tiff_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/generators/plucker/CMakeFiles/okularGenerator_plucker_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/generators/epub/CMakeFiles/okularGenerator_epub_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../devel/chmlib/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/libkexiv2/buildlink3.mk"
.include "../../www/kjs/buildlink3.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../wip/kdegraphics-mobipocket/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
