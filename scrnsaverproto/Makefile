# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 02:44:06 jeremy-c-reed Exp $
#

DISTNAME=		scrnsaverproto-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC1/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		ScrnSaver extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/scrnsaverproto.pc.in
USE_LANGUAGES=		# empty

.include "../../wip/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
