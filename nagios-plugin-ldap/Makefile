# $NetBSD: Makefile,v 1.4 2004/05/09 21:01:42 blef Exp $
#

.include "../../wip/nagios-plugins/Makefile.common"

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios ldap plugin

BINARY_TARGET=	check_ldap

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
