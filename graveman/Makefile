# $NetBSD: Makefile,v 1.2 2005/04/11 21:12:35 tvierling Exp $
#

DISTNAME=		graveman-0.3.7
CATEGORIES=		wip
MASTER_SITES=		http://savannah.nongnu.org/download/graveman/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://graveman.tuxfamily.org/
COMMENT=		GTK2 frontend for CD writting and audio conversion

DEPENDS+=		sox>12:../../audio/sox
DEPENDS+=		dvd+rw-tools>5.21:../../sysutils/dvd+rw-tools

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
