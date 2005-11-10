# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 13:07:46 ghen Exp $

DISTNAME=		skipstone-0.9.3
CATEGORIES=		www
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		geert.hendrickx@ua.ac.be
HOMEPAGE=		http://www.muhri.net/skipstone/
COMMENT=		Light and fast Gecko-based browser

GNU_CONFIGURE=		yes

# it doesn't build with firefox headers, otherwise I'd make it an option
MOZILLA=		mozilla-gtk2

CONFIGURE_ARGS+=	--with-mozilla-includes=${PREFIX}/include/${MOZILLA}
CONFIGURE_ARGS+=	--with-mozilla-libs=${PREFIX}/lib/${MOZILLA}
CONFIGURE_ARGS+=	--enable-cvs-mozilla

.include "../../www/${MOZILLA}/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
