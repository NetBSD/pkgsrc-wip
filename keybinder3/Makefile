# $NetBSD: Makefile,v 1.3 2015/04/06 10:44:24 krytarowski Exp $

.include "../../wip/keybinder/Makefile.common"

PKGNAME=	keybinder3
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+3 registering keyboard shortcuts
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--disable-python

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
