# $NetBSD: Makefile,v 1.2 2003/04/09 01:23:55 marmfield Exp $
#

PKGNAME=	nagios-plugin-snmp-${PLUGINSVERSION}
PKGREVISION=	# not defined

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios snmp plugins

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}:../../wip/nagios-plugins
DEPENDS+=       p5-Net-SNMP*:../../net/p5-Net-SNMP

.include "../../wip/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_snmp check_hpjd
SCRIPT_TARGET=	check_ifoperstatus check_ifstatus
#SCRIPT_TARGET+=	check_breeze check_wave

.include "../../wip/nagios-plugins/Makefile.plugin"

.include "../../net/net-snmp/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
