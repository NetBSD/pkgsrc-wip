# $NetBSD: Makefile,v 1.1 2012/01/26 11:14:54 mwdavies Exp $

DISTNAME=	analitza-${_KDE_VERSION}
CATEGORIES=	math
COMMENT=	KDE library for mathematical features

.include "../../wip/kde4/Makefile.kde4"

USE_GNU_READLINE=	yes
BROKEN_READLINE_DETECTION=	yes

.include "../../wip/kde4/kde4.mk"

.include "../../devel/readline/buildlink3.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
