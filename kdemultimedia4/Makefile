# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 04:02:34 mwdavies Exp $

DISTNAME=	kdemultimedia-${_KDE_VERSION}
CATEGORIES=	multimedia
COMMENT=	Multimedia tools for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

BUILD_MAKE_FLAGS+= VERBOSE=1

#REPLACE_BASH+= pics/oxygen/scalable/export_pngs.sh

#REPLACE_PERL+= \
#	khelpcenter/searchhandlers/khc_docbookdig.pl.cmake \
#	khelpcenter/searchhandlers/khc_htdig.pl.cmake \
#	khelpcenter/searchhandlers/khc_htsearch.pl \
#	khelpcenter/searchhandlers/khc_mansearch.pl \
#	kioslave/info/kde-info2html

#CONF_FILES+=	${PREFIX}/share/examples/kdebase-runtime4/kde-information.menu \
#                ${PKG_SYSCONFDIR}/xdg/menus/kde-information.menu

#INSTALLATION_DIRS+=	${PKGMANDIR}/man1

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
