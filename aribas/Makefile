# $NetBSD$

DISTNAME=	aribas165
PKGNAME=	aribas-1.6.5
CATEGORIES=	math
MASTER_SITES=	https://www.mathematik.uni-muenchen.de/~forster/sw/UNIX_LINUX/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html
COMMENT=	Interactive interpreter for big integer arithmetic
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
BUILD_DIRS=	src

EGDIR=			${PREFIX}/share/examples/aribas
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1  ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aribas ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/aribas.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/aribas
	${INSTALL_DATA} ${WRKSRC}/doc/aridoc.txt \
		${DESTDIR}${PREFIX}/share/doc/aribas/
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${PREFIX}/share/examples/aribas/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/src/EL/aribas.el \
		${DESTDIR}${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
