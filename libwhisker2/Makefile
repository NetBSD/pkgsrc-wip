# $NetBSD: Makefile,v 1.2 2004/06/06 04:35:09 thomasklausner Exp $

DISTNAME=	libwhisker2-2.0
CATEGORIES=	security www
MASTER_SITES=	http://www.wiretrip.net/rfp/libwhisker/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.wiretrip.net/rfp/lw.asp
COMMENT=	Perl module geared specifically for HTTP testing

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay

USE_PERL5=      YES
REPLACE_PERL=	scripts/api_demo.pl scripts/crawl_demo.pl \
		scripts/simple_demo.pl

do-build:
	@cd ${WRKSRC} && ${PERL5} Makefile.pl lib

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/libwhisker2

	${INSTALL_DATA} ${WRKSRC}/docs/crawler.txt \
		${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/docs/whisker_hash.txt \
		${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif \
		${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS \
		${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/libwhisker2

	${INSTALL_SCRIPT} ${WRKSRC}/scripts/api_demo.pl \
		${PREFIX}/share/examples/libwhisker2
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/crawl_demo.pl \
		${PREFIX}/share/examples/libwhisker2
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/simple_demo.pl \
		${PREFIX}/share/examples/libwhisker2

	${INSTALL_DATA} ${WRKSRC}/LW2.pm \
		${PERL5_SITELIB}

.include "../../mk/bsd.pkg.mk"
