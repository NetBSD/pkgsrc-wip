# $NetBSD: Makefile,v 1.7 2004/09/13 19:44:08 minskim Exp $
#

DISTNAME=		libXfont-1.4.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xfont extension (Library)

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libXfont.la
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xfont.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
