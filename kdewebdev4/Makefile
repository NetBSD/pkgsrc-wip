# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 04:25:10 mwdavies Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
CATEGORIES=	www
COMMENT=	HTML editor and tools suitable for experienced web developers

.include "../../wip/kde4/Makefile.kde4"

BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
#.include "../../wip/kdebase-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
