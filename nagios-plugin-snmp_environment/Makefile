# $NetBSD: Makefile $

VERSION=	0.7
PKGREVISION=	1
PKGNAME=	nagios-plugin-snmp_environment-${VERSION}
COMMENT=	Check various hardware environmental sensors
CATEGORIES=	sysutils net
HOMEPAGE=	https://exchange.nagios.org/directory/Plugins/Hardware/Network-Gear/Cisco/Check-various-hardware-environmental-sensors/details

EXTRACT_SUFX=	# empty
DIST_SUBDIR=	check_snmp_environment-${VERSION}
MASTER_SITES=	-https://exchange.nagios.org/components/com_mtree/attachment.php?link_id=483&cf_id=24
DISTNAME=	check_snmp_environment.pl
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

DEPENDS+=	net-snmp-[0-9]*:../../net/net-snmp

WRKSRC=		${WRKDIR}

do-extract:
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

PLUGINDIR=		libexec/nagios
PLIST_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

REPLACE_PERL+=		${WRKSRC}/check_snmp_environment.pl

NO_BUILD=	YES

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/check_snmp_environment.pl ${DESTDIR}${PREFIX}/${PLUGINDIR}/check_snmp_environment

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
