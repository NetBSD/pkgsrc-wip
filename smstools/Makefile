# $NetBSD: Makefile,v 1.2 2008/05/04 20:16:59 shattered Exp $
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
INSTALLATION_DIRS+=	${EGDIR}
RCD_SCRIPTS=		smsd

WRKSRC=			${WRKDIR}/smstools3
BUILD_DIRS=		src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/smsd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/regular_run ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sendsms ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sms2html ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/sms2unicode ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/unicode2sms ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/smsd.conf.easy ${EGDIR}/smsd.conf

.include "../../mk/bsd.pkg.mk"
