# $NetBSD: Makefile,v 1.1 2009/08/01 20:04:55 genolopolis Exp $
#

DISTNAME=	cfengine-3.0.2b5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cfengine.org/tarballs/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://www.cfengine.org/
COMMENT=	cfengine is a tool for automating sysadmin administration
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=          YES
USE_TOOLS+=             flex yacc gmake
USE_LIBTOOL=		YES
USE_LANGUAGES= c c++
PKG_DESTDIR_SUPPORT=    user-destdir
BUILDLINK_TRANSFORM+=l:db:db4
CONFIGURE_ARGS+=        --with-berkeleydb=${BUILDLINK_PREFIX.db4:Q}
CONFIGURE_ARGS+=        --with-openssl=${BUILDLINK_PREFIX.openssl:Q}
CONFIGURE_ARGS+=        --with-pcre=${BUILDLINK_PREFIX.pcre:Q}

# url2pkg-marker (please do not remove this line.)
.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
