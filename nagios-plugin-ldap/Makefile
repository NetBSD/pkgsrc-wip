# $NetBSD: Makefile,v 1.5 2005/08/04 19:12:10 scott8586 Exp $
#

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}
PKGREVISION=	# not defined
CATEGORIES=	net sysutil databases

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios ldap plugin

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}:../../wip/nagios-plugins

.include "../../wip/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_ldap

.include "../../wip/nagios-plugins/Makefile.plugin"
.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
