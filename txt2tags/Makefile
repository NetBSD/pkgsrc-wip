# $NetBSD: Makefile,v 1.2 2006/07/31 20:08:27 dbolgheroni Exp $

DISTNAME=			txt2tags-2.3
CATEGORIES=			textproc
MASTER_SITES=			http://txt2tags.sourceforge.net/src/
EXTRACT_SUFX=			.tgz

MAINTAINER=			dbolgheroni@unifei.edu.br
HOMEPAGE=			http://txt2tags.sourceforge.net/
COMMENT=			Text formatting and conversion tool

PYTHON_PATCH_SCRIPTS=		txt2tags
PYTHON_VERSIONS_ACCEPTED=	24

NO_BUILD=			yes

DOC_DIR=			${PREFIX}/share/doc/${PKGBASE}
SAMPLES_DIR=			${PREFIX}/share/examples/${PKGBASE}

do-install:
	${INSTALL_DATA_DIR} ${DOC_DIR} ${SAMPLES_DIR} ${SAMPLES_DIR}/img
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.* ${SAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/samples/img/*.* ${SAMPLES_DIR}/img
	${INSTALL_MAN} ${WRKSRC}/doc/manpage.man ${PREFIX}/man/man1/txt2tags.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
