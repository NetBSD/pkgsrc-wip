# $NetBSD: Makefile,v 1.1 2007/12/02 18:34:10 adrian_p Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
COMPONENT=	relay
SUBDIR=		relay

DEPENDS+=	isc-dhcp-base-3.0.6:../../wip/isc-dhcp

RCD_SCRIPTS=	isc_dhcrelay
MAN_FILES=	man8/dhcrelay.8
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "../../wip/isc-dhcp/Makefile.common"
.include "../../mk/bsd.pkg.mk"
