# $NetBSD: Makefile,v 1.2 2007/12/02 18:34:10 adrian_p Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Client
COMPONENT=	client
SUBDIR=		client

CONF_FILES+=	${EGDIR}/dhclient.conf ${PKG_SYSCONFDIR}/dhclient.conf

DEPENDS+=	isc-dhcp-base-3.0.6:../../wip/isc-dhcp

RCD_SCRIPTS=	isc_dhclient
MAN_FILES=	man5/dhclient.conf.5 man5/dhclient.leases.5 \
		man8/dhclient-script.8 man8/dhclient.8
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/client/dhclient.conf ${EGDIR}

.include "../../wip/isc-dhcp/Makefile.common"
.include "../../mk/bsd.pkg.mk"
