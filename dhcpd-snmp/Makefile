# $NetBSD: Makefile,v 1.2 2015/06/10 13:43:17 ahp-nils Exp $
#

DISTNAME=		dhcpd-snmp-20160601
CATEGORIES=		net
MASTER_SITES=		-https://github.com/ohitz/dhcpd-snmp/archive/master.zip
EXTRACT_SUFX=		.zip

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://github.com/ohitz/dhcpd-snmp
COMMENT=		Extension for the Net-SNMP agent and the ISC DHCP server
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/dhcpd-snmp-master
USE_LANGUAGES=		# none
NO_BUILD=		yes

USE_TOOLS+=		find pax perl pod2man
REPLACE_PERL+=		dhcpd-snmp

DEPENDS+=		net-snmp-[0-9]*:../../net/net-snmp

.include "../../mk/bsd.prefs.mk"

NET_SNMP_MIBDIR=	share/snmp/mibs
EGDIR=			share/examples/dhcpd-snmp

BUILD_DEFS+=		VARBASE NET_SNMP_MIBDIR

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	dhcpd-snmp.conf.dist
SUBST_SED.paths+=	-e 's|@VARBASE@|${VARBASE}|g'
SUBST_STAGE.paths=	post-configure

CONF_FILES=		${PREFIX}/${EGDIR}/dhcpd-snmp.conf \
			${PKG_SYSCONFDIR}/dhcpd-snmp.conf

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man8 ${NET_SNMP_MIBDIR} ${EGDIR}

post-configure:
	cd ${WRKSRC} ; pod2man README.pod dhcpd-snmp.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dhcpd-snmp ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dhcpd-snmp.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/mibs/nettrack-dhcpd-snmp.mib \
		${DESTDIR}${PREFIX}/${NET_SNMP_MIBDIR}/nettrack-dhcpd-mib.txt
	${INSTALL_DATA} ${WRKSRC}/dhcpd-snmp.conf.dist \
		${DESTDIR}${PREFIX}/${EGDIR}/dhcpd-snmp.conf
	find ${WRKSRC}/cacti -type f -exec chmod ugo-x \{\} \;
	cd ${WRKSRC} ; ${PAX} -rw cacti ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
