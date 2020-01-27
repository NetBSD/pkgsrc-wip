# $NetBSD: Makefile,v 1.4 2012/10/01 20:12:48 asau Exp $
#

DISTNAME=		jalview_1.8
PKGNAME=		jalview_binary-1.8
WRKSRC=			${WRKDIR}/jalview_1.8
CATEGORIES=		biology
MASTER_SITES=		http://www.jalview.org/version118/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		https://www.jalview.org/
COMMENT=		Jalview is a multiple alignment editor written in java

USE_JAVA=		run
NO_CONFIGURE=		yes
NO_BUILD=		yes

post-extract:
	${MV} ${WRKSRC}/jalview.sh ${WRKSRC}/jalview.sh.in

pre-install:
	${SED} -e "s:@PREFIX@:${PREFIX}:g" <${WRKSRC}/README \
	      >${WRKSRC}/README.jalview
	${SED} -e "s:@PREFIX@:${PREFIX}:g" <${WRKSRC}/jalview.sh.in \
	      >${WRKSRC}/jalview.sh

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/jalview_1.8.jar ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/jalview.jar ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/jalview
	${INSTALL_DATA} ${WRKSRC}/jalview.sh ${DESTDIR}${PREFIX}/share/jalview
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/jalview
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/jalview/examples
	${INSTALL_DATA} ${WRKSRC}/examples/1hdc.pfam ${DESTDIR}${PREFIX}/share/jalview/examples

pre-check:
	${DESTDIR}${PREFIX}/bin/jalview.sh ${DESTDIR}${PREFIX}/share/jalview/examples/1hdc.pfam File PFAM

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
