# $NetBSD: Makefile,v 1.8 2011/01/17 10:48:04 emil_s Exp $
#

DISTNAME=		lhs2tex-1.12
PKGREVISION=		1
CATEGORIES=		print devel
MASTER_SITES=		http://www.iai.uni-bonn.de/~loeh/lhs2tex/
EXTRACT_SUFX=		.tar.bz2

HOMEPAGE=		http://www.iai.uni-bonn.de/~loeh/lhs2tex/
MAINTAINER=		esg@sdf.lonestar.org
COMMENT=		Preprocessor for typesetting Haskell sources with LaTeX
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/lhs2tex

.include "../../print/teTeX/module.mk"
.include "../../lang/ghc/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/polytable
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/lazylist
	${INSTALL_DATA} ${WRKSRC}/doc/Guide2.pdf ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/polytable/polytable.pdf ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/polytable/polytable.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/polytable
	${INSTALL_DATA} ${WRKSRC}/polytable/lazylist.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/lazylist

.include "../../mk/bsd.pkg.mk"
