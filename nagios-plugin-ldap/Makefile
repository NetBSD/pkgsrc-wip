# $NetBSD: Makefile,v 1.3 2003/04/22 13:27:02 thomasklausner Exp $
#

.include "../../wip/nagios-plugins/Makefile.common"

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios ldap plugin

BINARY_TARGET=	check_ldap

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../databases/openldap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
