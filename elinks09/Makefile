# $NetBSD: Makefile,v 1.6 2004/01/25 02:12:07 grantbeattie Exp $

DISTNAME=		elinks-0.9.0
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dawszy@arhea.net
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

CONFLICTS=		elinks-[0-9]*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--without-x --enable-256-colors
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.if defined(USE_LUA) && ${USE_LUA} == "yes" 
.include "../../lang/lua/buildlink2.mk"
.endif
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
