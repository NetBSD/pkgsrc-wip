# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 00:34:23 marmfield Exp $
#

PKGNAME=	nagios-plugin-snmp-${PLUGINSVERSION}
PKGREVISION=	# not defined

MAINTAINER=     murray@river-styx.org
COMMENT=	Nagios snmp plugins

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}:../../net/nagios-plugins
DEPENDS+=       p5-Net-SNMP*:../../net/p5-Net-SNMP

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_snmp check_hpjd
SCRIPT_TARGET=	check_ifoperstatus check_ifstatus
#SCRIPT_TARGET+=	check_breeze check_wave

.include "../../net/nagios-plugins/Makefile.plugin"

.include "../../net/net-snmp/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
