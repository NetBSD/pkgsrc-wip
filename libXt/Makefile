# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:35 grantbeattie Exp $
#

DISTNAME=		libXt-6.0-jcr3
PKGNAME=		libXt-6.0
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		x11 devel
MASTER_SITES=		http://www.reedmedia.net/misc/X/
#MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE=		http://www.freedesktop.org/Software/X11
COMMENT=		X Toolkit Intrinsics library

CONFLICTS+=		XFree86-libs-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/bin/makestrs) && !exists(/usr/bin/makestrs)
BUILD_DEPENDS+=		imake-[0-9]*:../../wip/imake
.endif

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xt.pc.in

.include "../../wip/libICE/buildlink2.mk"
.include "../../wip/libSM/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
