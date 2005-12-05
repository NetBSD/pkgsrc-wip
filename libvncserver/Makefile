# $NetBSD: Makefile,v 1.3 2005/12/05 22:27:46 rillig Exp $
#

DISTNAME=		LibVNCServer-0.7
PKGNAME=		libvncserver-0.7
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://libvncserver.sourceforge.net/
COMMENT=		Library for creating quick and easy VNC applications

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=        --prefix=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
