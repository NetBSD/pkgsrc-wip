# $NetBSD: Makefile,v 1.2 2004/12/02 22:42:28 daprice Exp $
#

DISTNAME=		dia2code-0.8.1
CATEGORIES=	 	devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dia2code/}

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://dia2code.sourceforge.net/
COMMENT=		Small utility used to generate code from a Dia diagram

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

pre-build:
	${SED}	-e 's:INCLUDES =:INCLUDES = -I${PREFIX}/include/libxml2/libxml :' \
	${WRKSRC}/Makefile > ${WRKSRC}/Makefile.temp
	${MV} ${WRKSRC}/Makefile.temp ${WRKSRC}/Makefile

	${SED}	-e 's:INCLUDES =:INCLUDES = -I${PREFIX}/include/libxml2/libxml :' \
	${WRKSRC}/dia2code/Makefile > ${WRKSRC}/dia2code/Makefile.temp
	${MV} ${WRKSRC}/dia2code/Makefile.temp ${WRKSRC}/dia2code/Makefile

	${SED}	-e 's:INCLUDES =:XML_INCLUDES = -I${PREFIX}/include/libxml2/libxml :' \
	${WRKSRC}/dia2code/docs/Makefile > ${WRKSRC}/dia2code/docs/Makefile.temp
	${MV} ${WRKSRC}/dia2code/docs/Makefile.temp ${WRKSRC}/dia2code/docs/Makefile

	${SED}	-e 's:INCLUDES =:XML_INCLUDES = -I${PREFIX}/include/libxml2/libxml :' \
	${WRKSRC}/dia2code/docs/en/Makefile > ${WRKSRC}/dia2code/docs/en/Makefile.temp
	${MV} ${WRKSRC}/dia2code/docs/en/Makefile.temp ${WRKSRC}/dia2code/docs/en/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dia2code/dia2code ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dia2code.1 ${PREFIX}/man/man1/dia2code.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dia2code
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dia2code/README

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
