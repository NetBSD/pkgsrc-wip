# $NetBSD: Makefile,v 1.16 2011/05/13 23:25:16 mwdavies Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

PYTHON_VERSIONS_ACCEPTED= 27 26 25
#make sure cmake picks up the same Python version as pkgsrc
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}
CMAKE_ARGS+=	-DLIBLZMA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.xz}/include
CMAKE_ARGS+=	-DLIBLZMA_LIBRARY:FILEPATH=${BUILDLINK_PREFIX.xz}/lib/liblzma.so

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_PYTHON+=	printer-applet/*.py

.include "options.mk"

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../wip/kde4/kde4.mk"

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../wip/kdebindings4-python/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
