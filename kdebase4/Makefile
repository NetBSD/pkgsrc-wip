# $NetBSD: Makefile,v 1.10 2011/05/13 23:25:14 mwdavies Exp $

DISTNAME=	kdebase-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Base modules for the KDE 4 integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_RUBY+=	apps/dolphin/src/khns/servicemenudeinstallation
REPLACE_RUBY+=	apps/dolphin/src/khns/servicemenuinstallation

.include "../../lang/ruby/replace.mk"

.include "../../wip/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
