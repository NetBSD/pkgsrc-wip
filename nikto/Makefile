# $NetBSD: Makefile,v 1.4 2003/09/14 22:23:37 adrian_p Exp $

DISTNAME=	nikto-1.30
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/source/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.cirt.net/code/nikto.shtml
COMMENT=	URL scanner used to search for known vulnerable CGIs on websites

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay
DEPENDS+=	nmap>=2.00:../../net/nmap

USE_PERL5=      YES
REPLACE_PERL=	nikto.pl

do-build:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/nikto.pl > \
		${WRKSRC}/nikto
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/config.txt > \
		${WRKSRC}/config.txt.sample

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nikto
	${INSTALL_DATA_DIR} ${PREFIX}/share/nikto
	${INSTALL_DATA_DIR} ${PREFIX}/share/nikto/docs
	${INSTALL_DATA_DIR} ${PREFIX}/share/nikto/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/nikto
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/nikto
	${INSTALL_DATA} ${WRKSRC}/docs/CHANGES.txt ${PREFIX}/share/nikto/docs
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${PREFIX}/share/doc/nikto
	${INSTALL_DATA} ${WRKSRC}/config.txt.sample \
		${PREFIX}/share/examples/nikto
	${INSTALL_SCRIPT} ${WRKSRC}/nikto ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/plugins/*.plugin ${PREFIX}/share/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/LW.pm ${PREFIX}/share/nikto/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.db ${PREFIX}/share/nikto/plugins

.include "../../mk/bsd.pkg.mk"

