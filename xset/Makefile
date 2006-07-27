# $NetBSD: Makefile,v 1.1.1.1 2006/07/27 15:45:44 jeremy-c-reed Exp $
#

DISTNAME=		xset-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 user preferences utility

GNU_CONFIGURE=		yes

USE_TOOLS+=		pkg-config

.include "../../wip/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
