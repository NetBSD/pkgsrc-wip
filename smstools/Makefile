# $NetBSD: Makefile,v 1.3 2012/10/07 15:29:10 asau Exp $
#

DISTNAME=		smstools3-3.0.10
PKGNAME=		smstools-3.0.10
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		http://smstools3.kekekasvi.com/packages/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://smstools3.kekekasvi.com/
COMMENT=		Send and receive short messages via GSM phones

USE_TOOLS+=		bash:run gmake
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
REPLACE_BASH=		scripts/sms2html scripts/sms2unicode scripts/regular_run scripts/unicode2sms

EGDIR=			${PREFIX}/share/examples/smstools
CONF_FILES=		${EGDIR}/smsd.conf ${PKG_SYSCONFDIR}/smsd.conf
INSTALLATION_DIRS+=	bin sbin ${EGDIR}
RCD_SCRIPTS=		smsd

WRKSRC=			${WRKDIR}/smstools3
BUILD_DIRS=		src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/smsd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/regular_run ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sendsms ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sms2html ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sms2unicode ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/unicode2sms ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/smsd.conf.easy ${DESTDIR}${EGDIR}/smsd.conf

.include "../../mk/bsd.pkg.mk"
