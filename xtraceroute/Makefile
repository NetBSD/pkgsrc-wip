# $NetBSD: Makefile,v 1.1.1.1 2011/02/19 15:59:17 thomasklausner Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_FEATURES=		snprintf

CPPFLAGS+=		-I${BUILDLINK_PREFIX.gtkglarea}/include/gtkgl-2.0

#CONFIGURE_ARGS+= --with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
# XXX Actually, Mesa's in X11PREFIX too, but as our tiff is in LOCALBASE
# and xtraceroute doesn't have a switch to tell it so (yet?), we abuse
# the --with-GL-prefix switch for this.
#CONFIGURE_ARGS+= --with-GL-prefix=${LOCALBASE:Q}
#CONFIGURE_ARGS+= --with-lib-MesaGL

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CONFIGURE_ARGS+=	--with-traceroute=/usr/etc/traceroute
.endif

INSTALLATION_DIRS+=	share/xtraceroute

#post-install:
	#${INSTALL_DATA} ${WRKDIR}/hosts.cache    ${DESTDIR}${PREFIX}/share/xtraceroute/hosts.cache
	#${INSTALL_DATA} ${WRKDIR}/networks.cache ${DESTDIR}${PREFIX}/share/xtraceroute/networks.cache

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkglarea2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
