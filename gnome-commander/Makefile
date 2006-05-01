# $NetBSD: Makefile,v 1.1.1.1 2006/05/01 11:10:09 ondratu Exp $
#

DISTNAME=		gnome-commander-1.1.7
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-commander/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://www.nongnu.org/gcmd/
COMMENT=		GNOME Commander is a fast and powerful graphical filemanager


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
