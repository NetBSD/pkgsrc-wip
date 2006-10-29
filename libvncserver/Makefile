# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:46 shattered Exp $
#

DISTNAME=		LibVNCServer-0.7
PKGNAME=		libvncserver-0.7
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://libvncserver.sourceforge.net/
COMMENT=		Library for creating quick and easy VNC applications

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
