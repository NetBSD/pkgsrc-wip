# $NetBSD: Makefile,v 1.1.1.1 2003/09/18 01:24:43 minskim Exp $
#

DISTNAME=	prosper-1.00.4
PKGNAME=	tex-${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME:C/-[^-]*$//}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prosper/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} PPRblends.sty.gz

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://prosper.sourceforge.net/
COMMENT=	LaTeX class for writing transparencies

DEPENDS+=	teTeX*-bin-[0-9]*:../../print/teTeX-bin
DEPENDS+=	teTeX*-share-[0-9]*:../../print/teTeX-share

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
NO_CONFIGURE=	yes
NO_BUILD=	yes

TEXMF=		${LOCALBASE}/share/texmf
PROSPERDIR=	${TEXMF}/tex/latex/misc/prosper

DOCS=		AUTHORS ChangeLog FAQ INSTALL NEWS README TODO \
		TROUBLESHOOTINGS doc/compilation.eps doc/compilation.fig \
		doc/prosper-doc.pdf doc/prosper-doc.tex \
		doc/prosper-structure.eps doc/prosper-structure.fig \
		doc/prosper-tour.pdf doc/prosper-tour.ps doc/prosper-tour.tex \
		doc/rotation.ps doc/rotation.tex
DOCDIR=		${LOCALBASE}/share/doc/prosper
EXAMPLESDIR=	${LOCALBASE}/share/examples/prosper

post-extract:
	${GZCAT} -c ${DISTDIR}/PPRblends.sty.gz > \
		${WRKSRC}/contrib/PPRblends.sty

do-install:
	${INSTALL_DATA_DIR} ${PROSPERDIR}/contrib/img
	${INSTALL_DATA_DIR} ${PROSPERDIR}/designer
	${INSTALL_DATA_DIR} ${PROSPERDIR}/img
	${INSTALL_DATA} ${WRKSRC}/*.sty ${PROSPERDIR}
	${INSTALL_DATA} ${WRKSRC}/*.cls ${PROSPERDIR}
	${INSTALL_DATA} ${WRKSRC}/img/*.gif ${PROSPERDIR}/img
	${INSTALL_DATA} ${WRKSRC}/img/*.ps  ${PROSPERDIR}/img
	${INSTALL_DATA} ${WRKSRC}/contrib/*.sty ${PROSPERDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/*.ps  ${PROSPERDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/*.tex ${PROSPERDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/img/*.ps ${PROSPERDIR}/contrib/img
	${INSTALL_DATA} ${WRKSRC}/designer/prosper* ${PROSPERDIR}/designer
	${LOCALBASE}/bin/mktexlsr
	${INSTALL_DATA_DIR} ${DOCDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCDIR}."
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/doc-examples/Example* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.include "../../mk/bsd.pkg.mk"
