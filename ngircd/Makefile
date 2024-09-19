# $NetBSD$

DISTNAME=	ngircd-25
CATEGORIES=	chat
MASTER_SITES=	http://ngircd.barton.de/pub/ngircd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ngircd.barton.de/pub/ngircd/
COMMENT=	Free, portable and lightweight IRC server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

RCD_SCRIPTS+=	ngircd

CONF_FILES+=	${PREFIX}/share/examples/ngircd/sample-ngircd.conf ${PKG_SYSCONFDIR}/ngircd.conf

INSTALLATION_DIRS+=	share/examples/ngircd

.include "options.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/doc/ngircd/sample-ngircd.conf ${DESTDIR}${PREFIX}/share/examples/ngircd/
	${RM} ${DESTDIR}${PREFIX}/share/doc/ngircd/HowToRelease.txt
	${RM} ${DESTDIR}${PREFIX}/share/doc/ngircd/INSTALL
	${RM} ${DESTDIR}${PREFIX}/etc/ngircd.conf

.include "../../mk/bsd.pkg.mk"
