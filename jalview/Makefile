# $NetBSD: Makefile,v 1.1.1.1 2004/11/19 19:26:01 daprice Exp $
#

DISTNAME=		jalview_1.8
PKGNAME=		jalview_binary-1.8
WRKSRC=			${WRKDIR}/jalview_1.8
CATEGORIES=		biology
MASTER_SITES=		http://www.jalview.org/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.jalview.org/
COMMENT=		Jalview is a multiple alignment editor written in java

USE_JAVA=		run
NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_BUILDLINK3=		yes

post-extract:
	${MV} ${WRKSRC}/jalview.sh ${WRKSRC}/jalview.sh.in

pre-install:
	${SED} -e "s:@PREFIX@:${PREFIX}:g" <${WRKSRC}/README \
	      >${WRKSRC}/README.jalview
	${SED} -e "s:@PREFIX@:${PREFIX}:g" <${WRKSRC}/jalview.sh.in \
	      >${WRKSRC}/jalview.sh

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/jalview_1.8.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/jalview.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/jalview
	${INSTALL_DATA} ${WRKSRC}/jalview.sh ${PREFIX}/share/jalview
	${INSTALL_DATA} ${WRKSRC}/README.jalview ${PREFIX}/share/jalview
	${INSTALL_DATA_DIR} ${PREFIX}/share/jalview/examples
	${INSTALL_DATA} ${WRKSRC}/examples/1hdc.pfam ${PREFIX}/share/jalview/examples

pre-check:
	${PREFIX}/bin/jalview.sh ${PREFIX}/share/jalview/examples/1hdc.pfam File PFAM

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
