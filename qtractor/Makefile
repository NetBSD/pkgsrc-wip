# $NetBSD$
#

DISTNAME=	qtractor-0.7.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qtractor/}

MAINTAINER=	gianni-pkgsrc-wip@daprile.net
HOMEPAGE=	http://qtractor.sourceforge.net/
COMMENT=	Qt Audio/MIDI multi-track sequencer application
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

QTDIR?=			${PREFIX}/qt5
CONFIGURE_ENV+=		QTDIR=${QTDIR:Q}
MAKE_ENV+=		QTDIR=${QTDIR:Q}

.for t in lupdate lrelease moc qmake uic
TOOLS_CREATE+=		${t}
TOOLS_PATH.${t}=	${QTDIR}/bin/${t}
.endfor

.include "options.mk"

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
