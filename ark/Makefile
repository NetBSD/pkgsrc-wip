# $NetBSD: Makefile,v 1.1 2012/01/24 19:40:55 mwdavies Exp $

DISTNAME=	ark-${_KDE_VERSION}
CATEGORIES=	archivers
COMMENT=	for managing various archive formats within the KDE environment

.include "../../wip/kde4/Makefile.kde4"

.include "../../wip/kde4/kde4.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
