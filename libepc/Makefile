# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:38 asau Exp $

DISTNAME=		libepc-0.3.11
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libepc/0.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://live.gnome.org/libepc/
COMMENT=		Easy Publish and Consume Library

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake intltool pkg-config
PKGCONFIG_OVERRIDE=	libepc-1.0.pc.in libepc-ui-1.0.pc.in

GNU_CONFIGURE=		YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
