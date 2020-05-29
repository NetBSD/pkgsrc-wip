# $NetBSD: Makefile,v 1.1 2015/06/06 13:52:41 krytarowski Exp $

DISTNAME=	accountsservice-0.6.55
CATEGORIES=	sysutils
MASTER_SITES=	https://www.freedesktop.org/software/accountsservice/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/accountsservice/
COMMENT=	Set of D-Bus interfaces for accessing account information
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dintrospection=false
MESON_ARGS+=	-Dsystemdsystemunitdir=no

.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
