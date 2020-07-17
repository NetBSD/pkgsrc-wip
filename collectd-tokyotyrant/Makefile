# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	tokyotyrant

COMMENT=		Statistics collection daemon - tokyotyrant plugin

.include "../../databases/tokyotyrant/buildlink3.mk"
COLLECTD_LIB.tokyotyrant=	${BUILDLINK_PREFIX.tokyotyrant}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
