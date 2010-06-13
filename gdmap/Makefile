# $NetBSD: Makefile,v 1.10 2010/06/13 22:47:04 thomasklausner Exp $
#

DISTNAME=		gdmap-0.7.5
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdmap/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://gdmap.sourceforge.net/
COMMENT=		Tool to visualize disk space

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config msgfmt xgettext perl intltool

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
