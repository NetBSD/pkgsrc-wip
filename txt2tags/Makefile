# $NetBSD: Makefile,v 1.10 2014/01/25 10:45:28 thomasklausner Exp $
#

DISTNAME=	txt2tags-2.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=txt2tags/}

MAINTAINER=	dbolgheroni@unifei.edu.br
HOMEPAGE=	https://txt2tags.org/
COMMENT=	Text formatting and conversion tool
LICENSE=	gnu-gpl-v2

REPLACE_PYTHON=		txt2tags

USE_PKGLOCALEDIR=	yes
NO_BUILD=		yes
USE_LANGUAGES=		# none

DOC_DIR=		${PREFIX}/share/doc/${PKGBASE}
SAMPLES_DIR=		${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${DOC_DIR} ${SAMPLES_DIR}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA_DIR} ${DOC_DIR} ${SAMPLES_DIR} ${DESTDIR}${SAMPLES_DIR}/img
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags ${DESTDIR}${PREFIX}/bin
	${CP} -R ${WRKSRC}/doc/* ${DESTDIR}${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.* ${DESTDIR}${SAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/samples/img/*.* ${DESTDIR}${SAMPLES_DIR}/img
	${INSTALL_MAN} ${WRKSRC}/doc/English/manpage.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/txt2tags.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
