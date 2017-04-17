# $NetBSD$

GITHUB_PROJECT=    gat
DISTNAME=          1.0
PKGNAME=           ${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=        sysutils
MASTER_SITES=      ${MASTER_SITE_GITHUB:=RyuKojiro/}
DIST_SUBDIR=       ${GITHUB_PROJECT}

MAINTAINER=        daniel+netbsd@loffgren.org
HOMEPAGE=          ${MASTER_SITE_GITHUB:=RyuKojiro/gat/}
COMMENT=           GTK ACPI Tray Battery Monitor
LICENSE=           mit
ONLY_FOR_PLATFORM= NetBSD-*-*

WRKSRC=            ${WRKDIR}/gat-1.0
INSTALLATION_DIRS= bin ${PKGMANDIR}/man1
DEPENDS+=          gtk3+-[0-9]*:../../x11/gtk3

USE_TOOLS+=        pkg-config

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
