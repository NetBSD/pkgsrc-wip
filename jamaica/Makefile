# $NetBSD: Makefile,v 1.4 2005/11/02 18:00:17 thomasklausner Exp $
#

DISTNAME=		jamaica-1.0
CATEGORIES=		lang
MASTER_SITES=		http://www.judoscript.com/store/
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.judoscript.com/articles/jamaica.html
COMMENT=		JVM Macro Assembler language

DEPENDS+=		java-bcel>=5.1:../../wip/java-bcel
DEPENDS+=		java-asm>=1.4.2:../../wip/java-asm
NO_BUILD=		yes

SUBST_CLASSES+=		jamaica
SUBST_STAGE.jamaica=	do-configure
SUBST_FILES.jamaica=	jamaica.sh
SUBST_SED.jamaica+=	-e 's,@PREFIX@,${PREFIX},g'

post-extract:
	${CP} ${FILESDIR}/jamaica.sh.in ${WRKSRC}/jamaica.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/jamaica.jar ${PREFIX}/lib/java/
	${INSTALL_SCRIPT} ${WRKSRC}/jamaica.sh ${PREFIX}/bin/jamaica
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/jamaica/
	${INSTALL_DATA} ${WRKSRC}/examples/* \
			${PREFIX}/share/examples/jamaica/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
