# $NetBSD: Makefile,v 1.1.1.1 2005/11/11 23:58:54 emil_s Exp $
#

DISTNAME=		lhs2tex-1.10pre
CATEGORIES=		print devel
MASTER_SITES=		http://www.cs.uu.nl/~andres/lhs2tex/
EXTRACT_SUFX=		.tar.bz2

HOMEPAGE=		http://www.cs.uu.nl/~andres/lhs2tex/
MAINTAINER=		emil@math.su.se
COMMENT=		Preprocessor for typesetting Haskell sources with LaTeX
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/lhs2tex


# We must convert ${PREFIX}/share to a comma separated list of quoted strings
# e.g. /usr/pkg/share -> "usr","pkg","share"
PREFIX_HS_cmd=		${ECHO} ${PREFIX}/share | \
			${SED} -e 's;^/;;'  \
			-e 's;/;\\",\\";g' \
			-e 's;\(.*\);\\"\1\\";'
PREFIX_HS=		${PREFIX_HS_cmd:sh}

post-patch:
	${MV} ${WRKSRC}/FileNameUtils.lhs ${WRKSRC}/FileNameUtils.lhs.orig
	${SED} -e "s/@PREFIX_HS@/${PREFIX_HS}/"  \
		${WRKSRC}/FileNameUtils.lhs.orig \
		> ${WRKSRC}/FileNameUtils.lhs

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
	${LOCALBASE}/bin/texconfig rehash
	${LOCALBASE}/bin/mktexlsr


.include "../../mk/tex.buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
