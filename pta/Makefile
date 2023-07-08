# $NetBSD$

DISTNAME=	pta-0.1
CATEGORIES=	finance
MASTER_SITES=	https://mandoc.bsd.lv/pta/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mandoc.bsd.lv/pta/release/
COMMENT=	Reads and writes bookkeeping journals
LICENSE=	isc

USE_LANGUAGES=	# none
USE_TOOLS=	perl:run
REPLACE_PERL=	pta.pl

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
#CONF_FILES=	${EGDIR}/journal.example.en ${PKG_SYSCONFDIR}/${PKGBASE}/journal.example.en
#CONF_FILES=	${EGDIR}/accounts.example.de \
#		${PKG_SYSCONFDIR}/${PKGBASE}/accounts.example.de
#CONF_FILES=	${EGDIR}/accounts.example.en \
		${PKG_SYSCONFDIR}/${PKGBASE}/accounts.example.en

do-build:
	${RM} '${WRKSRC}/Makefile'

do-install:
	${INSTALL_SCRIPT_DIR} '${DESTDIR}${PREFIX}/bin'
	${INSTALL_SCRIPT} '${WRKSRC}/pta.pl' '${DESTDIR}${PREFIX}/bin/pta'

	${INSTALL_MAN_DIR} '${DESTDIR}${PREFIX}/${PKGMANDIR}/man1'
	${INSTALL_MAN} '${WRKSRC}/pta.1' \
		'${DESTDIR}${PREFIX}/${PKGMANDIR}/man1'

	${INSTALL_MAN_DIR} '${DESTDIR}${PREFIX}/${PKGMANDIR}/man5'
	${INSTALL_MAN} '${WRKSRC}/pta-accounts.5' \
		'${DESTDIR}${PREFIX}/${PKGMANDIR}/man5'
	${INSTALL_MAN} '${WRKSRC}/pta-journal.5' \
		'${DESTDIR}${PREFIX}/${PKGMANDIR}/man5'

	${INSTALL_MAN_DIR} '${DESTDIR}${PREFIX}/${PKGMANDIR}/man7'
	${INSTALL_MAN} '${WRKSRC}/pta-glossary.7' \
		'${DESTDIR}${PREFIX}/${PKGMANDIR}/man7'

	${INSTALL_DATA_DIR} '${DESTDIR}${EGDIR}'
	${INSTALL_DATA} '${WRKSRC}/accounts.example.de' '${DESTDIR}${EGDIR}'

	${INSTALL_DATA_DIR} '${DESTDIR}${EGDIR}'
	${INSTALL_DATA} '${WRKSRC}/accounts.example.en' '${DESTDIR}${EGDIR}'

	${INSTALL_DATA_DIR} '${DESTDIR}${EGDIR}'
	${INSTALL_DATA} '${WRKSRC}/journal.example.en' '${DESTDIR}${EGDIR}'

.include "../../mk/bsd.pkg.mk"
