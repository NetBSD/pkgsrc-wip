# $NetBSD: Makefile,v 1.6 2004/05/09 02:39:34 minskim Exp $
#

DISTNAME=		libXt-0.1.4
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/xlibs-1.0/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/X11
COMMENT=		X Toolkit Intrinsics library

CONFLICTS+=		XFree86-libs-[0-9]*

.include "../../mk/bsd.prefs.mk"

# now includes and builds makestrs
#.if !exists(${X11BASE}/bin/makestrs) && !exists(/usr/bin/makestrs)
#BUILD_DEPENDS+=		imake-[0-9]*:../../wip/imake
#.endif

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	xt.pc.in

post-extract:
	${MV} ${WRKSRC}/ObjectP.h ${WRKSRC}/include/X11/

.include "../../wip/libICE/buildlink2.mk"
.include "../../wip/libSM/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
