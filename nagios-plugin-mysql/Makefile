# $NetBSD: Makefile,v 1.8 2005/11/03 14:52:17 rillig Exp $
#

PKGNAME=	nagios-plugin-mysql-${PLUGINSVERSION}
CATEGORIES=   	net sysutil databases

MAINTAINER=     tech-pkg@NetBSD.org
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
