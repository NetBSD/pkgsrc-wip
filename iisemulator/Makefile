# $NetBSD: Makefile,v 1.7 2012/09/30 05:23:06 asau Exp $

DISTNAME=	iisemulator-0.95
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=iisemul8/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	https://sourceforge.net/projects/iisemul8/
COMMENT=	IIS emulator

IISEMUL8=	${PREFIX}/share/iisemulator
USE_TOOLS+=	perl pax
REPLACE_PERL=	iisemul8.pl

DOC_FILES=	AUTHORS COPYING README BUGS TODO CHANGES
EG_FILES=	EXAMPLE.honeyd EXAMPLE.socat

do-build:
	@${SED} -e 's#@IISEMUL8@#${IISEMUL8}#g' < ${WRKSRC}/iisemul8.pl > \
			${WRKSRC}/iisemul8

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/iisemulator
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/iisemulator/docs
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/iisemulator/docs/notes
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/iisemulator
	${INSTALL_DATA_DIR} ${DESTDIR}${IISEMUL8}/iis_data
	${INSTALL_DATA_DIR} ${DESTDIR}${IISEMUL8}/wwwroot

	${INSTALL_SCRIPT} ${WRKSRC}/iisemul8 ${DESTDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/docs/honeyd.conf \
		${DESTDIR}${PREFIX}/share/doc/iisemulator/docs

	${INSTALL_DATA} ${WRKSRC}/docs/notes/*.txt \
		${DESTDIR}${PREFIX}/share/doc/iisemulator/docs/notes

	for FILE in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$FILE \
			${DESTDIR}${PREFIX}/share/doc/iisemulator; \
	done

	for FILE in ${EG_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$FILE \
			${DESTDIR}${PREFIX}/share/examples/iisemulator; \
	done

	cd ${WRKSRC}/iis_data && pax -rw . ${DESTDIR}${IISEMUL8}/iis_data
	cd ${WRKSRC}/wwwroot && pax -rw . ${DESTDIR}${IISEMUL8}/wwwroot

.include "../../mk/bsd.pkg.mk"
