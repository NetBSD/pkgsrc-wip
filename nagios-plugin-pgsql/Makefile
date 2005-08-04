# $NetBSD: Makefile,v 1.6 2005/08/04 19:09:11 scott8586 Exp $
#

PKGNAME=	nagios-plugin-pgsql-${PLUGINSVERSION}
PKGREVISION=	# not defined
CATEGORIES=   	net sysutil databases

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios pgsql plugin

DEPENDS+=       nagios-plugins-${PLUGINSVERSION}:../../wip/nagios-plugins

CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.pgsql-lib}
#CPPFLAGS+=		-I${PGSQL_PREFIX}/include/pgsql

.include "../../wip/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_pgsql

.include "../../wip/nagios-plugins/Makefile.plugin"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
