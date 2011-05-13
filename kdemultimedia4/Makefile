# $NetBSD: Makefile,v 1.12 2011/05/13 23:25:15 mwdavies Exp $

DISTNAME=	kdemultimedia-${_KDE_VERSION}
CATEGORIES=	multimedia
COMMENT=	Multimedia tools for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_BASH+=	kioslave/audiocd/upgrade-metadata.sh

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../wip/kde4/kde4.mk"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libtunepimp/buildlink3.mk"
.include "../../audio/libmusicbrainz/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.xine-lib?=	xine-lib>=1.1.19nb1
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
