# $NetBSD: Makefile,v 1.2 2007/03/01 19:12:18 shattered Exp $
#

DISTNAME=	liblo-0.23
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=liblo/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://liblo.sourceforge.net/
COMMENT=	Lightweight Open Sound Control implementation

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	liblo.pc.in

.include "../../mk/bsd.pkg.mk"
