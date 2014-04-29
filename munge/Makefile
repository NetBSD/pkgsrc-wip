# $NetBSD: Makefile,v 1.5 2014/04/29 19:38:51 outpaddling Exp $

DISTNAME=	munge-0.5.11
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://munge.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://code.google.com/p/munge/
COMMENT=	Authentication service for creating and validating credentials
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

BUILD_DEFS+=	VARBASE
USE_TOOLS=	perl pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
INSTALLATION_DIRS+=	lib/pkgconfig

OWN_DIRS=	${VARBASE}/lib/munge ${VARBASE}/log/munge ${VARBASE}/run/munge

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
