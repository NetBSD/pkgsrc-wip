# $NetBSD: Makefile,v 1.13 2005/05/24 10:30:32 rillig Exp $
#

DISTNAME=		libXt-0.1.5
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X Toolkit Intrinsics library

CONFLICTS+=		XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

# now includes and builds makestrs
#.if !exists(${X11BASE}/bin/makestrs) && !exists(/usr/bin/makestrs)
#BUILD_DEPENDS+=		imake-[0-9]*:../../wip/imake
#.endif

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	xt.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../wip/libICE/buildlink3.mk"
.include "../../wip/libSM/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
