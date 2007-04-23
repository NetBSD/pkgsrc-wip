# $NetBSD: Makefile,v 1.4 2007/04/23 15:29:37 emil_s Exp $
#

DISTNAME=	alex-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.haskell.org/alex/dist/${VERSION}/
DISTFILES=	${DISTNAME}.tar.gz
DISTFILES+=	alex-doc-html-2.1.0.tar.gz
SITES.alex-doc-html-2.1.0.tar.gz=http://www.haskell.org/alex/doc/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://www.haskell.org/alex/
COMMENT=	Tool for generating lexical analysers in Haskell

VERSION =	2.1.0

USE_TOOLS+=	gmake perl
GNU_CONFIGURE=	yes

#EXTRACT_ONLY=	${DISTNAME}-src.tar.gz alex-html.tar.gz

EGDIR=		${PREFIX}/share/examples/alex
DOCDIR=		${PREFIX}/share/doc/alex

do-configure:
	cd ${WRKSRC:Q} &&                             \
	runhaskell Setup.lhs configure                \
		--ghc                                 \
		--prefix=${PREFIX:Q}                  \
		--with-compiler=${PREFIX:Q}/bin/ghc  \
		--with-hc-pkg=${PREFIX:Q}/bin/ghc-pkg

do-build:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs install

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${FIND} ${WRKSRC}/examples -type f \
		-exec ${INSTALL_DATA} \{\} ${EGDIR} \;
	${INSTALL_DATA_DIR} ${DOCDIR}
#	${INSTALL_DATA} ${DISTDIR}/alex.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/alex-html/* ${DOCDIR}


.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
