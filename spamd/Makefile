# $NetBSD: Makefile,v 1.8 2004/07/18 17:44:59 ppostma Exp $

DISTNAME=       spamd-20040609
CATEGORIES=     mail
MASTER_SITES=   http://nedbsd.nl/~ppostma/pf/

MAINTAINER=     peter@pointless.nl
HOMEPAGE=       http://nedbsd.nl/~ppostma/pf-lkm.html
COMMENT=        OpenBSD spamd daemon which rejects false mail

ONLY_FOR_PLATFORM=      NetBSD-2*-*

USE_PKGINSTALL=         YES

CONF_FILES=	${PREFIX}/share/examples/spamd/spamd.conf ${PKG_SYSCONFDIR}/spamd.conf

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/spamd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/spamd.conf.cat5 ${PREFIX}/man/cat5/spamd.conf.0
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.cat8 ${PREFIX}/man/cat8/spamd.0
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.cat8 ${PREFIX}/man/cat8/spamd-setup.0
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.cat8 ${PREFIX}/man/cat8/spamdb.0
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.cat8 ${PREFIX}/man/cat8/spamlogd.0

	${INSTALL_PROGRAM} ${WRKSRC}/spamd-setup/spamd-setup ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamdb/spamdb ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/spamlogd/spamlogd ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spamd
	${INSTALL_DATA} ${WRKSRC}/etc/spamd.conf ${PREFIX}/share/examples/spamd

.include "../../mk/bsd.pkg.mk"
