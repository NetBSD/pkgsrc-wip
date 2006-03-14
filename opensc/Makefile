# $NetBSD: Makefile,v 1.3 2006/03/14 01:28:03 jlamwww Exp $

DISTNAME=      		opensc-0.10.0
CATEGORIES=     	security
MASTER_SITES= 		http://www.opensc.org/files/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE= 		http://www.opensc.org/openct/
COMMENT=		Smart Card Reader drivers and middleware

GNU_CONFIGURE= 		YES
USE_LIBTOOL=            YES
USE_OLD_DES_API=	YES
USE_TOOLS+= 		gmake pkg-config

.include "options.mk"

USE_OLD_DES_API=	YES
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-sensitive-logging

.include "../../devel/libltdl/buildlink3.mk"
.include "../../wip/openct/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
