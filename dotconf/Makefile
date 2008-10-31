# $NetBSD: Makefile,v 1.1.1.1 2008/10/31 20:39:29 shattered Exp $
#

DISTNAME=	dotconf-1.0.13
CATEGORIES=	devel
MASTER_SITES=	http://www.azzit.de/dotconf/download/v1.0/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://www.azzit.de/dotconf/
COMMENT=	Configuration file parser library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	dotconf.pc.in

.include "../../mk/bsd.pkg.mk"
