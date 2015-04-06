# $NetBSD: Makefile,v 1.5 2015/04/06 09:33:06 krytarowski Exp $

.include "Makefile.common"

CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for registering keyboard shortcuts
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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
