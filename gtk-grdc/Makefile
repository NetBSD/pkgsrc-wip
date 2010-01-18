# $NetBSD: Makefile,v 1.4 2010/01/18 09:38:23 thomasklausner Exp $
#

DISTNAME=	grdc-0.4.0
PKGNAME=	gtk-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grdc/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://grdc.sourceforge.net/
COMMENT=	Grdc is a remote desktop client based on GTK+

PKG_DESTDIR_SUPPORT=    user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool perl pkg-config gmake

DEPENDS+=	rdesktop>=1.6.0:../../net/rdesktop

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libvncserver=		libvncserver>=0.9.1
.include "../../net/libvncserver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.libgcrypt=		libgcrypt>=1.4.4
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libssh=		libssh>=0.11
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
