# $NetBSD$

DISTNAME=	picoLisp
PKGNAME=	PicoLisp-17.3.4
CATEGORIES=	lang
MASTER_SITES=	http://software-lab.de/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://picolisp.com/
COMMENT=	Simple programming language and application server framework
LICENSE=	mit

WRKSRC=	${WRKDIR}/picoLisp

BUILD_DIRS+=	src
USE_TOOLS+=	gmake

AUTO_MKDIRS=	yes

BIN_DIR=	${PREFIX}/bin
LIB_DIR=	${PREFIX}/lib

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths+=		bin/pil
SUBST_SED.fix-paths+=		-e 's,/usr/bin,${BIN_DIR},g'
SUBST_SED.fix-paths+=		-e 's,/usr/lib,${LIB_DIR},g'

do-install:
	${INSTALL_ENV} ${INSTALL_PROGRAM} ${WRKSRC}/bin/picolisp ${DESTDIR}${BIN_DIR}
	${INSTALL_ENV} ${INSTALL_SCRIPT} ${WRKSRC}/bin/pil ${DESTDIR}${BIN_DIR}
	${INSTALL_ENV} ${INSTALL_MAN} ${WRKSRC}/man/man1/picolisp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_ENV} ${INSTALL_MAN} ${WRKSRC}/man/man1/pil.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_ENV} ${INSTALL_SCRIPT} ${WRKSRC}/lib.l ${DESTDIR}${LIB_DIR}/picolisp
	${INSTALL_ENV} ${INSTALL_SCRIPT} ${WRKSRC}/lib/*.l ${DESTDIR}${LIB_DIR}/picolisp/lib

.include "../../mk/bsd.pkg.mk"
