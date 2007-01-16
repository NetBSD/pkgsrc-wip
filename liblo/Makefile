# $NetBSD: Makefile,v 1.1.1.1 2007/01/16 13:00:49 netcap Exp $
#

DISTNAME=	liblo-0.23
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=liblo/}

MAINTAINER=     jfranz@bsdprojects.net
HOMEPAGE=	http://liblo.sourceforge.net/
COMMENT=	Lightweight Open Sound Control implementation

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=  c

PKGCONFIG_OVERRIDE+=	liblo.pc.in

.include "../../mk/bsd.pkg.mk"
