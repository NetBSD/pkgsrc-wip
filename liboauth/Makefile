# $NetBSD: Makefile,v 1.1.1.1 2010/06/12 23:18:56 jihbed Exp $
#

DISTNAME=	liboauth-0.8.8
CATEGORIES=	security
MASTER_SITES=	http://liboauth.sourceforge.net/pool/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://liboauth.sourceforge.net/pool/
COMMENT=	C library for implementing oAuth 1.0 specification
LICENSE=	gnu-gpl-v2 AND mit

DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl

PKGCONFIG_OVERRIDE+=	oauth.pc.in

CONFIGURE_ARGS+=		--enable-nss

.include "../../devel/nss/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
