# $NetBSD: Makefile,v 1.2 2003/04/09 01:24:40 marmfield Exp $
#

.include "../../wip/nagios-plugins/Makefile.common"

PKGNAME=	nagios-plugin-ldap

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios ldap plugin

BINARY_TARGET=	check_ldap

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../databases/openldap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
