# $NetBSD: Makefile,v 1.3 2012/12/29 11:32:08 othyro Exp $
#

DISTNAME=	xtraceroute-0.9.2
CATEGORIES=	net x11
MASTER_SITES=	http://www.beebgames.com/sw/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.dtek.chalmers.se/~d3august/xt/index.html
HOMEPAGE=	http://www.beebgames.com/sw/gtk-ports.html
COMMENT=	Graphical version of traceroute, tracing the route IP packets go
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoheader autoconf gm4 gmake intltool msgfmt msgmerge
USE_TOOLS+=		pkg-config xgettext
USE_FEATURES=		snprintf

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.gtkglarea2}/include/gtkgl-2.0

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CONFIGURE_ARGS+=	--with-traceroute=/usr/etc/traceroute
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkglarea2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
