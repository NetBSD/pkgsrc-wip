# $NetBSD$

DISTNAME=	shotcut-src-190715
PKGNAME=	shotcut-19.07.15
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=mltframework/}
GITHUB_PROJECT=	shotcut
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.txz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.shotcut.org/
COMMENT=	Free, open source, cross-platform video editor
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/src/shotcut

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

CXXFLAGS+=	-DHAVE_LOCALE_H

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

USE_LANGUAGES=	c c++

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake PREFIX=${PREFIX}

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../wip/mlt/buildlink3.mk"
.include "../../multimedia/movit/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
