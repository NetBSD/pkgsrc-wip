# $NetBSD: Makefile,v 1.3 2005/04/11 21:13:12 tvierling Exp $

DISTNAME=	iisemulator-0.95
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=iisemul8/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://sourceforge.net/projects/iisemul8/
COMMENT=	IIS emulator

IISEMUL8=	${PREFIX}/share/iisemulator
USE_PERL5=	YES
REPLACE_PERL=	iisemul8.pl

DOC_FILES=	AUTHORS COPYING README BUGS TODO CHANGES
EG_FILES=	EXAMPLE.honeyd EXAMPLE.socat

do-build:
	@${SED} -e 's#@IISEMUL8@#${IISEMUL8}#g' < ${WRKSRC}/iisemul8.pl > \
			${WRKSRC}/iisemul8

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/iisemulator
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/iisemulator/docs
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/iisemulator/docs/notes
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/iisemulator
	${INSTALL_DATA_DIR} ${IISEMUL8}/iis_data
	${INSTALL_DATA_DIR} ${IISEMUL8}/wwwroot

	${INSTALL_SCRIPT} ${WRKSRC}/iisemul8 ${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/docs/honeyd.conf \
		${PREFIX}/share/doc/iisemulator/docs

	${INSTALL_DATA} ${WRKSRC}/docs/notes/*.txt \
		${PREFIX}/share/doc/iisemulator/docs/notes

	for FILE in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$FILE \
			${PREFIX}/share/doc/iisemulator; \
	done

	for FILE in ${EG_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$FILE \
			${PREFIX}/share/examples/iisemulator; \
	done

	cd ${WRKSRC}/iis_data && ${PAX} -rw . ${IISEMUL8}/iis_data
	cd ${WRKSRC}/wwwroot && ${PAX} -rw . ${IISEMUL8}/wwwroot

.include "../../mk/bsd.pkg.mk"
