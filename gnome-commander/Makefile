# $NetBSD: Makefile,v 1.2 2006/08/09 22:56:17 ondratu Exp $
#

DISTNAME=		gnome-commander-1.2.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-commander/1.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://www.nongnu.org/gcmd/
COMMENT=		GNOME Commander is a fast and powerful graphical filemanager

USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config perl

#Problem with heimdal, on witch this package is depend by another packages.
#Simple solution is delete link to fnmatch.h from work directory of package
#after make configure like this:
pre-build:
	rm ${WRKDIR}/.buildlink/include/krb5/fnmatch.h
	cd ${WRKSRC}/data; cp gnome-commander.desktop.in gnome-commander.desktop

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
