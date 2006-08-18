# $NetBSD: Makefile,v 1.1.1.1 2006/08/18 14:12:37 jeremy-c-reed Exp $
#

DISTNAME=		bdftopcf-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/app/
COMMENT=		BDF to PCF font converter for X11

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../wip/libXfont/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
