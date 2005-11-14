# $NetBSD: Makefile,v 1.2 2005/11/14 14:04:00 emil_s Exp $
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



# We must convert ${PREFIX} to a comma separated list of quoted strings
# e.g. /usr/pkg -> "usr","pkg"
PREFIX_HS_cmd=		${ECHO} ${PREFIX} |             \
			${SED}  -e 's|^/*||'            \
				-e 's|/*$$||'		\
				-e 's|/|","|g'    	\
				-e 's|\(.*\)|"\1"|'
PREFIX_HS=		${PREFIX_HS_cmd:sh}

# and then hardcode the path to directory where the latex format file is found
SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing hardcoded path
SUBST_FILES.path=	FileNameUtils.lhs
SUBST_SED.path=		-e 's|@PREFIX_HS@|${PREFIX_HS}|'

DOCDIR=			${PREFIX}/share/doc/lhs2tex


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
