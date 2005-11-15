# $NetBSD: Makefile,v 1.1.1.1 2005/11/15 14:32:42 emil_s Exp $
#

DISTNAME=	alex-2.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.haskell.org/alex/dist/
DISTFILES=	${DISTNAME}-src.tar.gz
DISTFILES+=	alex-html.tar.gz
DISTFILES+=	alex.ps
SITES_alex-html.tar.gz=http://www.haskell.org/alex/doc/
SITES_alex.ps=http://www.haskell.org/alex/doc/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://www.haskell.org/alex/
COMMENT=	Tool for generating lexical analysers in Haskell


USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

EXTRACT_ONLY=	${DISTNAME}-src.tar.gz alex-html.tar.gz

EGDIR=		${PREFIX}/share/examples/alex
DOCDIR=		${PREFIX}/share/doc/alex


post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${FIND} ${WRKSRC}/alex/examples -type f \
		-exec ${INSTALL_DATA} \{\} ${EGDIR} \;
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${DISTDIR}/alex.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/alex/* ${DOCDIR}


.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
