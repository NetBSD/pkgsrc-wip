# $NetBSD: Makefile,v 1.2 2007/12/12 19:26:04 mwdavies Exp $

DISTNAME=	kdemultimedia-${_KDE_VERSION}
CATEGORIES=	multimedia
COMMENT=	Multimedia tools for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_PERL+=	kscd/workman2cddb.pl

.include "../../wip/kde4/kde4.mk"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libtunepimp/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
#.include "../../wip/qimageblitz/buildlink3.mk"
#.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
