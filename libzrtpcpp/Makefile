# $NetBSD: Makefile,v 1.8 2012/03/26 14:04:02 othyro Exp $

DISTNAME=		libzrtpcpp-2.0.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.gnutelephony.org/
COMMENT=		ZRTP extension for GNU ccRTP
LICENSE=		gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_CMAKE=		yes
PKG_DESTDIR_SUPPORT=	destdir
#CMAKE_ARGS+=		-DLIBDIRNAME=lib # build ignores this

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7i

.include "../../wip/ccrtp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
