# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 03:22:41 jeremy-c-reed Exp $
#

DISTNAME=		compositeproto-0.2.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/
COMMENT=		Composite extension headers from modular X.org

CONFLICTS+=		compositeext-[0-9]*

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	${WRKSRC}/compositeproto.pc.in

.include "../../wip/fixesproto/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
