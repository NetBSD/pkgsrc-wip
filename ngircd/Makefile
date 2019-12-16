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
CONF_FILES+=            ${EGDIR}/sample-ngircd.conf ${PREFIX}/share/examples/ngircd/sample-ngircd.conf

.include "options.mk"


post-install:
	${MKDIR} ${PREFIX}/share/examples/ngircd

	${RM} ${DESTDIR}${EGDIR}/COPYING
	${RM} ${DESTDIR}${EGDIR}/HowToRelease.txt
	${RM} ${DESTDIR}${EGDIR}/INSTALL
	${RM} ${DESTDIR}${PREFIX}/etc/ngircd.conf

.include "../../mk/bsd.pkg.mk"
