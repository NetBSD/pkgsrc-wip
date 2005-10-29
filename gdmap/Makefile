# $NetBSD: Makefile,v 1.1.1.1 2005/10/29 05:55:29 dhowland Exp $
#

DISTNAME=		gdmap-0.7.0
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdmap/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://gdmap.sourceforge.net/
COMMENT=		Tool to visualize disk space

BUILD_USES_MSGFMT=      yes
GNU_CONFIGURE=		yes
USE_DIRS+=              xdg-1.2
USE_PKGLOCALEDIR=       yes
USE_TOOLS+=		gmake pkg-config

.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
