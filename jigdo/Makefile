# $NetBSD: Makefile,v 1.4 2003/07/18 03:38:50 bencollver Exp $
#

DISTNAME=		jigdo-0.6.9
CATEGORIES=		misc
MASTER_SITES=		http://home.in.tum.de/~atterer/jigdo/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://home.in.tum.de/~atterer/jigdo/
COMMENT=		download manager and ISO image constructor

DEPENDS+=		wget>=1.8.2:../../net/wget

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--without-gui

.include "../../www/libwww/buildlink2.mk"
.include "../../databases/db3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
