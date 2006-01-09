# $NetBSD: Makefile,v 1.1 2006/01/09 08:26:58 chriswareham Exp $
#

DISTNAME=		jack-audio-connection-kit-0.100.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jackit/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://jackit.sourceforge.net/
COMMENT=		JACK is a low-latency audio server

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	jack.pc.in

.include "../../mk/bsd.pkg.mk"
