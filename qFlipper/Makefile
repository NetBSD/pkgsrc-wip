# $NetBSD$

GITHUB_PROJECT=	qFlipper
GITHUB_TAG=	refs/tags/1.3.3
DISTNAME=	1.3.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=flipperdevices/}
DIST_SUBDIR=	${GITHUB_PROJECT}

GITHUB_SUBMODULES+=	pbatard	libwdi	v1.5.0	driver-tool/libwdi
GITHUB_SUBMODULES+=	nanopb	nanopb	0.4.8	3rdparty/nanopb

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flipperzero.one/update
COMMENT=	Flipper Zero firmware update tool
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/qFlipper-1.3.3
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

TOOL_DEPENDS+=	qt5-qtbase>=0:../../x11/qt5-qtbase
TOOL_DEPENDS+=	qt5-qttools>=0:../../x11/qt5-qttools

QMAKE=		${QTDIR}/bin/qmake
QMAKE_ARGS+=	PREFIX=${PREFIX:Q}

INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR:Q}

# _NETBSD_SOURCE pulls in major() and minor() macros in <sys/types.h>,
# which breaks some parts of qFlipper, so define standard feature
# macros instead to suppress this.  Somehow part of the build adds
# _NETBSD_SOURCE itself, so we have to remove it explicitly.
CFEATUREFLAGS+=		-D_ISOC99_SOURCE
CFEATUREFLAGS+=		-D_POSIX_C_SOURCE=200809L
_WRAP_EXTRA_ARGS.CC+=	${CFEATUREFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${CFEATUREFLAGS}
CWRAPPERS_PREPEND.cc+=	${CFEATUREFLAGS}
CWRAPPERS_PREPEND.cxx+=	${CFEATUREFLAGS}
BUILDLINK_TRANSFORM+=	rm:-D_NETBSD_SOURCE

BUILD_DIRS=	build

pre-configure:
	${RUN}cd ${WRKSRC:Q} && mkdir build

do-configure:
	@${STEP_MSG} Running qmake
	${RUN}${_ULIMIT_CMD}cd ${WRKSRC:Q}/build && \
	${PKGSRC_SETENV} ${CONFIGURE_ENV} \
		${QMAKE:Q} ../qFlipper.pro ${QMAKE_ARGS}

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
#.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
