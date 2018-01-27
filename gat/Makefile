# $NetBSD$

DISTNAME=		gat-1.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=RyuKojiro/}

MAINTAINER=		daniel+netbsd@loffgren.org
HOMEPAGE=		https://github.com/RyuKojiro/gat/
COMMENT=		GTK ACPI Tray Battery Monitor
LICENSE=		mit

ONLY_FOR_PLATFORM=	NetBSD-*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_TOOLS+=		pkg-config

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
