# $NetBSD: Makefile,v 1.4 2004/05/09 21:02:57 blef Exp $
#

.include "../../wip/nagios-plugins/Makefile.common"

PKGNAME=	nagios-plugin-mysql-${PLUGINSVERSION}
PKGREVISION=	# not defined

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios mysql plugin

BINARY_TARGET=	utils.o check_mysql

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
