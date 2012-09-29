# $NetBSD: Makefile,v 1.9 2012/09/29 00:50:36 asau Exp $
#

DISTNAME=		gnomad2-2.8.8
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnomad2/}

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://gnomad2.sourceforge.net/
COMMENT=		GTK+2 tool for managing Creative and Dell mp3 players
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_TOOLS+=		intltool pkg-config

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/libnjb/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
