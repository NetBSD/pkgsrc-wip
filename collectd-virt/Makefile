# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	virt

COMMENT=		Statistics collection daemon - virt plugin

.include "../../sysutils/libvirt/buildlink3.mk"
COLLECTD_LIB.virt=	${BUILDLINK_PREFIX.libvirt}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
