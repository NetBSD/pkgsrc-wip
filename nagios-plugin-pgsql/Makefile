# $NetBSD: Makefile,v 1.5 2004/07/25 16:22:58 marc Exp $
#

.include "../../wip/nagios-plugins/Makefile.common"

PKGNAME=	nagios-plugin-pgsql-${PLUGINSVERSION}
PKGREVISION=	# not defined

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios pgsql plugin

BINARY_TARGET=	utils.o check_pgsql

CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
CPPFLAGS+=		-I${PGSQL_PREFIX}/include/pgsql

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
