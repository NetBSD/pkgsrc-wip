# $NetBSD: Makefile,v 1.1.1.1 2008/11/24 08:58:36 minskim Exp $

DISTNAME=	texlive-20080822-texmf
PKGNAME=	texlive-texmf-base-2008
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/texlive/historic/2008/
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Essential texmf files of TeX Live

CONFLICTS+=	tetex-texmf-[0-9]*

EXTRACT_ELEMENTS=	${DISTNAME}/texmf-dist/bibtex \
			${DISTNAME}/texmf-dist/fonts \
			${DISTNAME}/texmf-dist/makeindex \
			${DISTNAME}/texmf-dist/omega \
			${DISTNAME}/texmf-dist/metafont \
			${DISTNAME}/texmf-dist/metapost \
			${DISTNAME}/texmf-dist/tex \
			${DISTNAME}/texmf/fmtutil \
			${DISTNAME}/texmf/fonts \
			${DISTNAME}/texmf/tex \
			${DISTNAME}/texmf/web2c
NO_BUILD=		yes
USE_TOOLS+=		pax

TEXMFDIRS=	share/texmf share/texmf-dist

.include "../../wip/kpathsea/buildlink3.mk"

post-extract:
.for texmf in texmf texmf-dist
	rm -f ${WRKSRC}/${texmf}/ls-R
.endfor
	rm -f ${WRKSRC}/texmf/web2c/fmtutil.cnf
	rm -f ${WRKSRC}/texmf/web2c/mktex.opt
	rm -f ${WRKSRC}/texmf/web2c/mktexdir
	rm -f ${WRKSRC}/texmf/web2c/mktexdir.opt
	rm -f ${WRKSRC}/texmf/web2c/mktexnam
	rm -f ${WRKSRC}/texmf/web2c/mktexnam.opt
	rm -f ${WRKSRC}/texmf/web2c/mktexupd
	rm -f ${WRKSRC}/texmf/web2c/texmf.cnf
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

do-install:
.for texmf in texmf texmf-dist
	cd ${WRKSRC}/${texmf} && pax -wrpm * ${DESTDIR}${PREFIX}/share/${texmf}
.endfor

.include "../../mk/bsd.pkg.mk"
