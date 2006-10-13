# $NetBSD: Makefile,v 1.18 2006/10/13 12:37:46 jeremy-c-reed Exp $
#

DISTNAME=		libXrender-0.9.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Render Library

CONFLICTS+=		Xrender-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xrender.pc.in

.include "../../mk/bsd.prefs.mk"
.if defined(X11_TYPE) && ${X11_TYPE} == "native"
CONFIGURE_ENV+=		X_CFLAGS="-I${X11BASE}/include"
CONFIGURE_ENV+=		X_LIBS="-L${X11BASE}/lib -lX11"
.  include "../../mk/x11.buildlink3.mk"

.  if !exists(${X11BASE}/include/X11/Xregion.h)
# Xregion.h is in Xorg; if missing copy to buildlink includes directory
pre-configure:
	${CP} ${FILESDIR}/Xregion.h ${BUILDLINK_DIR}/include/X11/
.  endif

.endif	# native

.if defined(X11_TYPE) && ${X11_TYPE} == "modular-xorg"
.  include "../../wip/libX11/buildlink3.mk"
.  include "../../wip/libXext/buildlink3.mk"
.endif

.include "../../x11/renderproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
