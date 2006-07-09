# $NetBSD: Makefile,v 1.4 2006/07/09 16:52:03 dhowland Exp $
#

DISTNAME=		gdmap-0.7.0
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdmap/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://gdmap.sourceforge.net/
COMMENT=		Tool to visualize disk space

GNU_CONFIGURE=		yes
USE_DIRS+=              xdg-1.2
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=       yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
