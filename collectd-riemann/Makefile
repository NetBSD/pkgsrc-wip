# $NetBSD: Makefile,v 1.9 2020/05/22 10:56:39 adam Exp $

COLLECTD_PACKAGE=	riemann
COLLECTD_PLUGINS=	write_riemann

COMMENT=		Statistics collection daemon - riemann plugin
PKGREVISION=		7

#.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../sysutils/riemann-client/buildlink3.mk"
#COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}
COLLECTD_LIB.riemann-client=${BUILDLINK_PREFIX.riemann-client}

BUILD_DEPENDS+=		protobuf-c-[0-9]*:../../devel/protobuf-c

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
