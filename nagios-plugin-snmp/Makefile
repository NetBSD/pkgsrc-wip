# $NetBSD: Makefile,v 1.4 2004/05/09 21:04:01 blef Exp $
#

PKGNAME=	nagios-plugin-snmp-${PLUGINSVERSION}
PKGREVISION=	# not defined

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios snmp plugins

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}:../../wip/nagios-plugins
DEPENDS+=       p5-Net-SNMP-[0-9]*:../../net/p5-Net-SNMP

.include "../../wip/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_snmp check_hpjd
SCRIPT_TARGET=	check_ifoperstatus check_ifstatus
#SCRIPT_TARGET+=	check_breeze check_wave

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
