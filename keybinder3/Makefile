# $NetBSD: Makefile,v 1.2 2015/04/06 10:40:32 krytarowski Exp $

.include "../../wip/keybinder/Makefile.common"

PKGNAME=	keybinder3
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+3 registering keyboard shortcuts
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

CONFIGURE_ARGS+=	--disable-static
CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--disable-python
# Don't rebuild the documentation
CONFIGURE_ARGS+=	--disable-gtk-doc

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
