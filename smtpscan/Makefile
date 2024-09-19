# $NetBSD: Makefile,v 1.7 2012/10/07 15:41:36 asau Exp $

DISTNAME=	smtpscan-${SSVERSION}
WRKSRC=		${WRKDIR}/smtpscan
CATEGORIES=	net mail
MASTER_SITES=	http://www.greyhats.org/outils/smtpscan/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.greyhats.org/outils/smtpscan/
COMMENT=	Remote SMTP version checker

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_TOOLS+=	perl
REPLACE_PERL=	src/smtpscan

SSVERSION?=	0.5
SSSHARE?=	${PREFIX}/share/smtpscan

do-build:
	@${SED} -e 's#@SSVERSION@#${SSVERSION}#g' \
		-e 's#@SSSHARE@#${SSSHARE}#g' \
		< ${WRKSRC}/docs/man/smtpscan.1 > ${WRKSRC}/docs/smtpscan.1

	@${SED} -e 's#@SSVERSION@#${SSVERSION}#g' \
		-e 's#@PREFIX@#${PREFIX}#g' \
		< ${WRKSRC}/src/smtpscan > ${WRKSRC}/smtpscan

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SSSHARE}

	${INSTALL_DATA} ${WRKSRC}/src/fingerprints ${DESTDIR}${SSSHARE}
	${INSTALL_DATA} ${WRKSRC}/src/tests ${DESTDIR}${SSSHARE}
	${INSTALL_SCRIPT} ${WRKSRC}/smtpscan ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/smtpscan.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
