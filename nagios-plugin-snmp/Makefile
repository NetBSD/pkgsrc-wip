# $NetBSD: Makefile,v 1.5 2005/08/04 19:00:41 scott8586 Exp $
#

PKGNAME=	nagios-plugin-snmp-${PLUGINSVERSION}
PKGREVISION=	# not defined
CATEGORIES=     net sysutil

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios snmp plugins

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}:../../wip/nagios-plugins
DEPENDS+=       p5-Net-SNMP-[0-9]*:../../net/p5-Net-SNMP

.include "../../wip/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_snmp check_hpjd
SCRIPT_TARGET=	check_ifoperstatus check_ifstatus
SCRIPT_TARGET+=	check_breeze check_wave

.include "../../wip/nagios-plugins/Makefile.plugin"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
