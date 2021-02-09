# $NetBSD: Makefile $

REVISION=	363
PKGREVISION=	1
PKGNAME=	nagios-plugin-printer-${REVISION}
COMMENT=	Gather supply metrics from a printer via SNMP query
CATEGORIES=	sysutils net
DISTNAME=	check_printer
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	check_printer-${REVISION}
MASTER_SITES=	https://www.secure-computing.net/trac/export/${REVISION}/SCN%20Open%20Source/trunk/nagios/
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

DEPENDS+=	net-snmp-[0-9]*:../../net/net-snmp

WRKSRC=		${WRKDIR}

do-extract:
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

PLUGINDIR=		libexec/nagios
PLIST_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

REPLACE_PERL+=		${WRKSRC}/check_printer

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing paths
SUBST_FILES.paths=	check_printer
SUBST_SED.paths=	-e 's;@LIBDIR@;${PREFIX}/${PLUGINDIR};'
SUBST_SED.paths+=	-e 's;@PREFIX@;${PREFIX};'

NO_BUILD=	YES

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/check_printer ${DESTDIR}${PREFIX}/${PLUGINDIR}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
