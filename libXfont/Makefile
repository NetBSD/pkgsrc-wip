# $NetBSD: Makefile,v 1.10 2005/07/21 16:34:03 thomasklausner Exp $
#

DISTNAME=		libXfont-1.4.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xfont extension (Library)

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xfont.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
