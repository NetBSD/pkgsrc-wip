# $NetBSD: Makefile,v 1.1.1.1 2004/01/31 07:44:15 jeremy-c-reed Exp $
#

DISTNAME=		libXmu-6.2.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/xlibs-1.0/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		X Miscellaneous Utilities library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmu.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmuu.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../wip/libXt/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
