# $NetBSD: Makefile,v 1.2 2004/10/13 16:09:16 ianharding Exp $
#

DISTNAME=		nsopenssl-3.0b23-src
PKGNAME=                aols-openssl-3.0b23
CATEGORIES=             www
MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=		iharding@destinydata.com
HOMEPAGE=		www.scottg.net
COMMENT=		OpenSSL module for aolserver

WRKSRC=                 ${WRKDIR}/${DISTNAME:S/-src//}

MAKE_FLAGS+=		INST=/${PREFIX}/include/nsd \
			OPENSSL=${PREFIX} \
			TCL_CC=gcc
CFLAGS+=		-I/usr/pkg/include/nsd/include

USE_BUILDLINK3=         yes
USE_GNU_TOOLS+=         make

.include "../../wip/aolserver4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
