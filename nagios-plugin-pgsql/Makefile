# $NetBSD: Makefile,v 1.4 2004/05/09 21:03:29 blef Exp $
#

.include "../../wip/nagios-plugins/Makefile.common"

PKGNAME=	nagios-plugin-pgsql-${PLUGINSVERSION}
PKGREVISION=	# not defined

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios pgsql plugin

BINARY_TARGET=	utils.o check_pgsql

CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.postgresql-lib}/include/pgsql

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
