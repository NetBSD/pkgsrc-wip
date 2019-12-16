# $NetBSD$

DISTNAME=	ngircd-25
CATEGORIES=	chat
MASTER_SITES=	http://ngircd.barton.de/pub/ngircd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ngircd.barton.de/pub/ngircd/
COMMENT=	Free, portable and lightweight IRC server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

RCD_SCRIPTS+=	ngircd

EGDIR=                  ${PREFIX}/share/doc/ngircd

CONF_FILES+=            ${EGDIR}/AUTHORS ${PKG_SYSCONFDIR}/ngircd/AUTHORS
CONF_FILES+=            ${EGDIR}/Bopm.txt ${PKG_SYSCONFDIR}/ngircd/Bopm.txt
CONF_FILES+=            ${EGDIR}/Capabilities.txt ${PKG_SYSCONFDIR}/ngircd/Capabilities.txt
CONF_FILES+=            ${EGDIR}/ChangeLog ${PKG_SYSCONFDIR}/ngircd/ChangeLog
CONF_FILES+=            ${EGDIR}/Commands.txt ${PKG_SYSCONFDIR}/ngircd/Commands.txt
CONF_FILES+=            ${EGDIR}/Contributing.txt ${PKG_SYSCONFDIR}/ngircd/Contributing.txt
CONF_FILES+=            ${EGDIR}/FAQ.txt ${PKG_SYSCONFDIR}/ngircd/FAQ.txt
CONF_FILES+=            ${EGDIR}/Modes.txt ${PKG_SYSCONFDIR}/ngircd/Modes.txt
CONF_FILES+=            ${EGDIR}/NEWS ${PKG_SYSCONFDIR}/ngircd/NEWS
CONF_FILES+=            ${EGDIR}/PAM.txt ${PKG_SYSCONFDIR}/ngircd/PAM.txt
CONF_FILES+=            ${EGDIR}/Platforms.txt ${PKG_SYSCONFDIR}/ngircd/Platforms.txt
CONF_FILES+=            ${EGDIR}/Protocol.txt ${PKG_SYSCONFDIR}/ngircd/Protocol.txt
CONF_FILES+=            ${EGDIR}/README ${PKG_SYSCONFDIR}/ngircd/README
CONF_FILES+=            ${EGDIR}/README-AUX.txt ${PKG_SYSCONFDIR}/ngircd/README-AUX.txt
CONF_FILES+=            ${EGDIR}/README-BeOS.txt ${PKG_SYSCONFDIR}/ngircd/README-BeOS.txt
CONF_FILES+=            ${EGDIR}/README-Interix.txt ${PKG_SYSCONFDIR}/ngircd/README-Interix.txt
CONF_FILES+=            ${EGDIR}/RFC.txt ${PKG_SYSCONFDIR}/ngircd/RFC.txt
CONF_FILES+=            ${EGDIR}/SSL.txt ${PKG_SYSCONFDIR}/ngircd/SSL.txt
CONF_FILES+=            ${EGDIR}/Services.txt ${PKG_SYSCONFDIR}/ngircd/Services.txt
CONF_FILES+=            ${EGDIR}/sample-ngircd.conf ${PKG_SYSCONFDIR}/ngircd/sample-ngircd.conf

.include "options.mk"

post-install:
	${MKDIR} ${PKG_SYSCONFDIR}/ngircd
	${RM} ${DESTDIR}${EGDIR}/COPYING
	${RM} ${DESTDIR}${EGDIR}/HowToRelease.txt
	${RM} ${DESTDIR}${EGDIR}/INSTALL
	${RM} ${DESTDIR}${PREFIX}/etc/ngircd.conf

.include "../../mk/bsd.pkg.mk"
