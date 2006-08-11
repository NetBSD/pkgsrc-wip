# $NetBSD: Makefile,v 1.2 2006/08/11 18:15:52 bartoszkuzma Exp $
#

DISTNAME=		bincimap-1.2.13final
PKGNAME=		${DISTNAME:S/final//}
CATEGORIES=		mail
MASTER_SITES=		http://www.bincimap.org/dl/tarballs/1.2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.bincimap.org/
COMMENT=		Modular IMAP server for Maildir

DEPENDS+=		checkpassword-[0-9]*:../../sysutils/checkpassword

USE_LANGUAGES+=		c++
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/bincimap
CONF_FILES=		${EGDIR}/bincimap.conf ${PKG_SYSCONFDIR}/bincimap.conf

.include "options.mk"

do-install:
	cd ${WRKSRC} && ${MAKE_PROGRAM} -DPKGSRC_INSTALL install

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/bincimap.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/toimapdir ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/tomaildir++ ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/xinetd-bincimap ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/xinetd-bincimaps ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/service/run ${EGDIR}/run-supervise
	${INSTALL_DATA} ${WRKSRC}/service/run-ssl ${EGDIR}/run-ssl-supervise
	${INSTALL_DATA} ${WRKSRC}/service/log/run ${EGDIR}/run-multilog
	${INSTALL_DATA} ${WRKSRC}/service/log/run-ssl ${EGDIR}/run-ssl-multilog

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
