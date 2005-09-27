# $NetBSD: Makefile,v 1.7 2005/09/27 16:10:01 thomasklausner Exp $
#

PKGNAME=	nagios-plugin-pgsql-${PLUGINSVERSION}
PKGREVISION=	# not defined
CATEGORIES=   	net sysutil databases

MAINTAINER=     tech-pkg@NetBSD.org
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
