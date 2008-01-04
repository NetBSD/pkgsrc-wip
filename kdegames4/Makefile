# $NetBSD: Makefile,v 1.2 2008/01/04 10:39:08 mwdavies Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

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

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
#.include "../../wip/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
