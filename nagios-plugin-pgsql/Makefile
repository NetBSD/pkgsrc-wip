# $NetBSD: Makefile,v 1.2 2003/04/09 01:25:25 marmfield Exp $
#

.include "../../wip/nagios-plugins/Makefile.common"

PKGNAME=	nagios-plugin-pgsql
PKGREVISION=	# not defined

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios pgsql plugin

BINARY_TARGET=	utils.o check_pgsql

CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.postgresql-lib}/include/pgsql

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
