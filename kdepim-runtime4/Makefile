# $NetBSD: Makefile,v 1.4 2011/05/19 20:27:27 mwdavies Exp $

#DISTNAME=	kdepim-runtime-${_KDE_VERSION}
DISTNAME=	kdepim-runtime-4.4.11.1
MASTER_SITES=	${MASTER_SITE_KDE:=kdepim-4.4.11.1/src/}
CATEGORIES=	misc
COMMENT=	Runtime requirements for the KDE PIM tools

.include "../../wip/kde4/Makefile.kde4"

# tar: Invalid header, starting valid header search.
EXTRACT_USING=	gtar

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../wip/kde4/kde4.mk"

.include "../../wip/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
