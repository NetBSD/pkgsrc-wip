# $NetBSD: Makefile,v 1.1.1.1 2007/10/06 02:17:31 othyro Exp $

DISTNAME=		libzrtpcpp-0.9.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.gnutelephony.org/
COMMENT=		ZRTP extension for GNU ccRTP

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++ fortran
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${BUILDLINK_PREFIX.openssl}/include/openssl
CPPFLAGS+=		-I${BUILDLINK_PREFIX.commoncpp2}/include/cc++2

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7i

.include "../../wip/ccrtp/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
