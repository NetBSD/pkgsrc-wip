# $NetBSD: Makefile,v 1.7 2015/06/07 14:24:48 yrmt Exp $

DISTNAME=	libepc-0.4.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libepc/0.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://live.gnome.org/libepc/
COMMENT=	Easy Publish and Consume Library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt msgmerge perl pkg-config xgettext

PKGCONFIG_OVERRIDE=	libepc-1.0.pc.in libepc-ui-1.0.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no --enable-gtk-doc-html=no
CONFIGURE_ARGS+=	--enable-gtk-doc-pdf=no

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtk3=	build
.include "../../x11/gtk3/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
