# $NetBSD: Makefile,v 1.8 2010/06/13 22:47:05 thomasklausner Exp $
#

DISTNAME=		gnomad2-2.8.8
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnomad2/}

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://gnomad2.sourceforge.net/
COMMENT=		GTK+2 tool for managing Creative and Dell mp3 players
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_TOOLS+=		intltool pkg-config

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/libnjb/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
