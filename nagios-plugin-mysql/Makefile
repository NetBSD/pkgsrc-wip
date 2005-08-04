# $NetBSD: Makefile,v 1.6 2005/08/04 19:05:31 scott8586 Exp $
#

PKGNAME=	nagios-plugin-mysql-${PLUGINSVERSION}
PKGREVISION=	# not defined
CATEGORIES=   	net sysutil databases

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios mysql plugin

DEPENDS+=       nagios-plugins-${PLUGINSVERSION}:../../wip/nagios-plugins

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
#LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../wip/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_mysql

.include "../../wip/nagios-plugins/Makefile.plugin"
.include "../../mk/mysql.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
