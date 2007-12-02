# $NetBSD: Makefile,v 1.2 2007/12/02 22:19:54 adrian_p Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
COMPONENT=	relay
SUBDIR=		relay

RCD_SCRIPTS=	isc_dhcrelay
MAN_FILES=	man8/dhcrelay.8
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "../../wip/isc-dhcp/Makefile.common"
.include "../../wip/isc-dhcp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
