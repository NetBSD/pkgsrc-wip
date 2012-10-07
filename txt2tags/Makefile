# $NetBSD: Makefile,v 1.9 2012/10/07 17:17:53 asau Exp $
#

DISTNAME=	txt2tags-2.5
CATEGORIES=			textproc
MASTER_SITES=	http://txt2tags.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=			dbolgheroni@unifei.edu.br
HOMEPAGE=			http://txt2tags.sourceforge.net/
COMMENT=			Text formatting and conversion tool

PYTHON_PATCH_SCRIPTS=		txt2tags

USE_PKGLOCALEDIR=	yes
NO_BUILD=			yes
USE_LANGUAGES=	# none

DOC_DIR=			${PREFIX}/share/doc/${PKGBASE}
SAMPLES_DIR=			${PREFIX}/share/examples/${PKGBASE}

do-install:
	${INSTALL_DATA_DIR} ${DOC_DIR} ${SAMPLES_DIR} ${SAMPLES_DIR}/img
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.* ${SAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/samples/img/*.* ${SAMPLES_DIR}/img
	${INSTALL_MAN} ${WRKSRC}/doc/manpage.man ${PREFIX}/${PKGMANDIR}/man1/txt2tags.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
