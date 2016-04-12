# $NetBSD: Makefile,v 1.5 2013/02/02 13:20:14 shattered Exp $
#

DISTNAME=		smstools3-3.1.15
PKGNAME=		${DISTNAME:S/smstools3/smstools/}
CATEGORIES=		comms
MASTER_SITES=		http://smstools3.kekekasvi.com/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://smstools3.kekekasvi.com/
COMMENT=		Send and receive short messages via GSM phones
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		bash:run gmake

WRKSRC=			${WRKDIR}/smstools3

REPLACE_BASH=		scripts/sms2html scripts/sms2unicode scripts/regular_run scripts/unicode2sms

BUILD_DEFS+=		VARBASE

CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
CPPFLAGS+=		-DSMS_DIR="\"${VARBASE}/spool/sms\""
LDFLAGS.SunOS+=		-lnsl -lsocket

EGDIR=			${PREFIX}/share/examples/smstools
CONF_FILES=		${EGDIR}/smsd.conf ${PKG_SYSCONFDIR}/smsd.conf

OWN_DIRS+=		${VARBASE}/spool/sms
OWN_DIRS+=		${VARBASE}/spool/sms/checked
OWN_DIRS+=		${VARBASE}/spool/sms/incoming
OWN_DIRS+=		${VARBASE}/spool/sms/outgoing

BUILD_DIRS=		src
INSTALLATION_DIRS+=	bin sbin ${EGDIR}

RCD_SCRIPTS=		smsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/smsd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/regular_run ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sendsms ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sms2html ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sms2unicode ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/unicode2sms ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/smsd.conf.easy ${DESTDIR}${EGDIR}/smsd.conf

.include "../../mk/bsd.pkg.mk"
