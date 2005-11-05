# $NetBSD: Makefile,v 1.1.1.1 2005/11/05 19:44:37 dhowland Exp $
#

PKGNAME=		pornview-0.2
DISTNAME=		pornview_0.2pre1.orig
CATEGORIES=		graphics
MASTER_SITES=		http://ftp.debian.org/debian/pool/main/p/pornview/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://pornview.sourceforge.net/
COMMENT=		GTK+ image viewer

WRKSRC=			${WRKDIR}/pornview-0.2.0pre1

BUILD_USES_MSGFMT=      yes
GNU_CONFIGURE=          yes
USE_DIRS+=              xdg-1.2
USE_LIBTOOL=            yes
USE_PKGLOCALEDIR=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
