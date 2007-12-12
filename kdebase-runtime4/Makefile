# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 03:25:42 mwdavies Exp $

DISTNAME=	kdebase-runtime-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Runtime requirements for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_BASH+= pics/oxygen/scalable/export_pngs.sh

REPLACE_PERL+= \
	khelpcenter/searchhandlers/khc_docbookdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htsearch.pl \
	khelpcenter/searchhandlers/khc_mansearch.pl \
	kioslave/info/kde-info2html

CONF_FILES+=	${PREFIX}/share/examples/kdebase-runtime4/kde-information.menu \
                ${PKG_SYSCONFDIR}/xdg/menus/kde-information.menu

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdepimlibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
