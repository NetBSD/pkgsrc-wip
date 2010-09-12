# $NetBSD: Makefile,v 1.4 2010/09/12 15:52:18 jihbed Exp $
#

DISTNAME=	notify-sharp_0.4.0~r2998.orig
PKGNAME=	notify-sharp-0.4.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/n/notify-sharp/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.ndesk.org/NotifySharp
COMMENT=	C\# bindings for libnotify
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/notify-sharp-0.4.0
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	notify-sharp.pc.in


.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
