# $NetBSD: Makefile,v 1.3 2005/05/24 10:29:58 rillig Exp $
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
USE_TOOLS+=		gmake

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
