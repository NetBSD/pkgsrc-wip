# $NetBSD: Makefile,v 1.1.1.1 2006/04/28 02:46:19 jeremy-c-reed Exp $
#

DISTNAME=		xinit-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/app/
COMMENT=		Utilities for starting the X Window System server

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../wip/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
