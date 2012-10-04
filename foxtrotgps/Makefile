# $NetBSD: Makefile,v 1.1 2012/10/04 00:45:36 khorben Exp $

DISTNAME=	foxtrotgps-1.1.1
CATEGORIES=	geography
MASTER_SITES=	http://www.foxtrotgps.org/releases/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.foxtrotgps.org/
COMMENT=	GPS application

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_TOOLS+=	intltool
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
