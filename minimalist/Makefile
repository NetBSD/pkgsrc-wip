# $NetBSD: Makefile,v 1.11 2012/10/03 14:17:22 asau Exp $
#

DISTNAME=	minimalist-2.5.3
CATEGORIES=	mail
MASTER_SITES=	http://www.mml.org.ua/LIST/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.mml.org.ua/
COMMENT=	Minimalistic Mailing Lists Manager

USE_TOOLS+=	perl
REPLACE_PERL=	${WRKSRC}/minimalist.pl
REPLACE_PERL+=	${WRKSRC}/contrib/minimalist_request.pl

EGDIR=		${PREFIX}/share/examples/minimalist/
CONF_FILES=	${EGDIR}/minimalist.conf ${PKG_SYSCONFDIR}/minimalist.conf

SUBST_CLASSES+=	path
SUBST_STAGE.path=post-patch
SUBST_FILES.path=minimalist.conf-sample
SUBST_FILES.path+=minimalist.pl
SUBST_FILES.path+=contrib/minimalist_request.pl
SUBST_SED.path= -e 's,/usr/local,${PREFIX},'

INSTALLATION_DIRS=	bin

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/minimalist/sample
	# cfgfiles
	${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample \
		${DESTDIR}${PREFIX}/etc/minimalist.conf
	${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample \
		${DESTDIR}${PREFIX}/share/examples/minimalist/minimalist.conf
	# examples
	${INSTALL_DATA} ${WRKSRC}/sample/lists.lst \
		${DESTDIR}${PREFIX}/share/examples/minimalist/
	${INSTALL_DATA} ${WRKSRC}/sample/sample/* \
		${DESTDIR}${PREFIX}/share/examples/minimalist/sample/
	# documentation
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/minimalist/FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ/* \
		${DESTDIR}${PREFIX}/share/doc/minimalist/FAQ/
.for _file_ in README CHANGES.txt virtual-domains.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${_file_} \
		${DESTDIR}${PREFIX}/share/doc/minimalist/
.endfor
	# scripts
	${INSTALL_SCRIPT} ${WRKSRC}/minimalist.pl \
			${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/minimalist_request.pl \
			${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
