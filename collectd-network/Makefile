# $NetBSD: Makefile,v 1.3 2017/06/14 13:42:53 fhajny Exp $

COLLECTD_PACKAGE=	network

COMMENT=		Statistics collection daemon - network plugin

.include "../../security/libgcrypt/buildlink3.mk"
COLLECTD_LIB.gcrypt=	${BUILDLINK_PREFIX.libgcrypt}/bin/libgcrypt-config

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
