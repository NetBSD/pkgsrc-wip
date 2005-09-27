# $NetBSD: Makefile,v 1.6 2005/09/27 16:10:01 thomasklausner Exp $
#

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}
PKGREVISION=	# not defined
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
