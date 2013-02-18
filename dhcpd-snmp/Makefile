# $NetBSD: Makefile,v 1.1 2013/02/18 08:22:56 ahp-nils Exp $
#

DISTNAME=		dhcpd-snmp-0.2
CATEGORIES=		net
MASTER_SITES=	http://www.net-track.ch/php/d.php?f=/opensource/dhcpd-snmp/

MAINTAINER=		ahp-nils@users.sourceforge.net
HOMEPAGE=		http://www.net-track.ch/opensource/dhcpd-snmp/
COMMENT=		Extension for the Net-SNMP agent and the ISC DHCP server
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=		perl:run
DOCDIR=			share/doc/dhcpd-snmp
DATADIR=		share/dhcpd-snmp
#CONF_FILES=		${PKG_SYSCONFDIR}/dhcpd-snmp.conf

AUTO_MKDIRS=	yes
INSTALLATION_DIRS+=		sbin ${PKGMANDIR}/man8 ${DOCDIR} ${DATADIR} ${DATADIR}/mibs

INSTALL_UNSTRIPPED=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpd-snmp ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dhcpd-snmp.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/mibs/nettrack-dhcpd-snmp.mib ${DESTDIR}${PREFIX}/${DATADIR}/mibs
	${INSTALL_DATA} ${WRKSRC}/mibs/nettrack.mib ${DESTDIR}${PREFIX}/${DATADIR}/mibs

.include "../../mk/bsd.pkg.mk"
