# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 00:36:31 marmfield Exp $
#

.include "../../net/nagios-plugins/Makefile.common"

PKGNAME=	nagios-plugin-mysql
PKGREVISION=	# not defined

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios mysql plugin

BINARY_TARGET=	utils.o check_mysql

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../net/nagios-plugins/Makefile.plugin"

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
