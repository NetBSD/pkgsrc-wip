# $NetBSD: Makefile,v 1.5 2006/08/02 18:12:33 dhowland Exp $
#

DISTNAME=		gdmap-0.7.5
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdmap/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://gdmap.sourceforge.net/
COMMENT=		Tool to visualize disk space

GNU_CONFIGURE=		yes
USE_DIRS+=              xdg-1.2
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=       yes
USE_TOOLS+=		gmake pkg-config msgfmt xgettext perl

.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
