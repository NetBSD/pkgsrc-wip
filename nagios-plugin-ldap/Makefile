# $NetBSD: Makefile,v 1.7 2005/11/03 14:52:17 rillig Exp $
#

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}
CATEGORIES=	net sysutil databases

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	Nagios ldap plugin

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}:../../wip/nagios-plugins

.include "../../wip/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_ldap

.include "../../wip/nagios-plugins/Makefile.plugin"
.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
