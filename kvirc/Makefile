# $NetBSD$

DISTNAME=	kvirc-5.2.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=kvirc/}
GITHUB_TAG=	refs/tags/${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/KVIrc-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kvirc.net/
COMMENT=	QT based irc client
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl msgmerge msgfmt xgettext pkg-config

.include "options.mk"

# "Under Solaris, both usleep() and threads implementation are based
# on SIGALARM. KVIrc uses both, and this could lead to some spontaneous
# application quits. This option enables a workaround for this problem."
.if ${OPSYS} == "SunOS"
CMAKE_CONFIGURE_ARGS+=	-DWANT_IGNORE_SIGALARM=ON
.endif

CMAKE_CONFIGURE_ARGS+=	-DMANDIR=man

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
#.include "../../lang/python/pyversion.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
