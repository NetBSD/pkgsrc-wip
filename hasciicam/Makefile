# $NetBSD: Makefile,v 1.8 2012/09/29 17:05:53 asau Exp $
#

DISTNAME=		hasciicam_1.3
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		graphics net
MASTER_SITES=		https://files.dyne.org/hasciicam/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ascii.dyne.org/
COMMENT=		Live ascii video on the web
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-* NetBSD-*-*

.include "../../graphics/aalib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
