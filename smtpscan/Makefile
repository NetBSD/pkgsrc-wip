# $NetBSD: Makefile,v 1.2 2004/04/26 14:46:03 adrian_p Exp $

DISTNAME=	smtpscan-${SSVERSION}
WRKSRC=         ${WRKDIR}/smtpscan
CATEGORIES=	net mail
MASTER_SITES=	http://www.greyhats.org/outils/smtpscan/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.greyhats.org/outils/smtpscan/
COMMENT=	Remote SMTP version checker

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_PERL5=	YES
NO_BUILDLINK=	YES
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

do-install:
	${INSTALL_DATA_DIR} ${SSSHARE}

	${INSTALL_DATA} ${WRKSRC}/src/fingerprints ${SSSHARE}
	${INSTALL_DATA} ${WRKSRC}/src/tests ${SSSHARE}
	${INSTALL_SCRIPT} ${WRKSRC}/smtpscan ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/smtpscan.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
