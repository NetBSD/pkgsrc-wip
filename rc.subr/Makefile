# $NetBSD: Makefile,v 1.3 2005/09/28 20:50:11 rillig Exp $
#

DISTNAME=		rc.subr-20030912
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		reed@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Documentation/rc/
COMMENT=		Portable NetBSD rc.subr implementation for pkgsrc

NOT_FOR_PLATFORM=	NetBSD-1.[5-9]*-* NetBSD-[2-9]*-* FreeBSD-[5-9]*-*

NO_CHECKSUM=		yes
NO_EXTRACT=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
NO_MTREE=		yes
USE_PKGINSTALL=		YES

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/rc.conf.example ${PKG_SYSCONFDIR}/rc.conf
# XXX consider not-hardcoding /etc/rc.subr in all rc.d scripts
SUPPORT_FILES=		${EGDIR}/rc.subr ${PKG_SYSCONFDIR}/rc.subr

# XXX not in PLIST because I am hoping that it will automatic soon
RCD_SCRIPTS=		DAEMON LOGIN NETWORKING SERVERS

PS_ARG=		"-ax"
PS_FORMAT=	"-o pid,command"
WHOAMI?=	/usr/bin/whoami

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PS_ARG=		"-ef"
PS_FORMAT=	"-o pid,comm"
WHOAMI=		"/usr/ucb/whoami"
.elif ${OPSYS} == "Linux"
PS_ARG=		"ax"
.endif

FILES_SUBST+=		NICE=${NICE}
FILES_SUBST+=		OPSYS=${OPSYS}
FILES_SUBST+=		PS=${PS}
FILES_SUBST+=		PS_ARG=${PS_ARG}
FILES_SUBST+=		PS_FORMAT=${PS_FORMAT}
FILES_SUBST+=		WHOAMI=${WHOAMI}

do-extract:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/rc.subr > ${WRKDIR}/rc.subr

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/rc.conf.example ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/rc.subr ${EGDIR}

.include "../../mk/bsd.pkg.mk"
