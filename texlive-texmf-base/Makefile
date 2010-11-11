# $NetBSD: Makefile,v 1.12 2010/11/11 14:01:55 makoto Exp $

DISTNAME=	texlive-20100722-texmf
PKGNAME=	texlive-texmf-base-2010
#PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/texlive/historic/2010/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Essential texmf files of TeX Live

CONFLICTS+=	tetex-texmf-[0-9]*
DEPENDS+=	tex-tetex-[0-9]*:../../print/tex-tetex
DEPENDS+=	tex-metafont-[0-9]*:../../fonts/tex-metafont
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

EXTRACT_ELEMENTS=	${DISTNAME}/texmf-dist/bibtex \
			${DISTNAME}/texmf-dist/fonts \
			${DISTNAME}/texmf-dist/makeindex \
			${DISTNAME}/texmf-dist/omega \
			${DISTNAME}/texmf-dist/metapost \
			${DISTNAME}/texmf-dist/tex \
			${DISTNAME}/texmf/fonts \
			${DISTNAME}/texmf/tex \
			${DISTNAME}/texmf/web2c
NO_BUILD=		yes
USE_TOOLS+=		pax
PKG_DESTDIR_SUPPORT=	user-destdir

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf ${PREFIX}/share/texmf-dist

.include "../../print/kpathsea/texmf.mk"

post-extract:
.for texmf in texmf texmf-dist
	rm -f ${WRKSRC}/${texmf}/ls-R
.endfor
	rm -rf ${WRKSRC}/texmf-dist/makeindex/plain
	rm -rf ${WRKSRC}/texmf-dist/tex/plain/base
	rm -rf ${WRKSRC}/texmf-dist/tex/plain/config
	rm -rf ${WRKSRC}/texmf/fonts/enc/dvips/tetex
	rm -rf ${WRKSRC}/texmf/fonts/map/dvipdfm/tetex
	rm -rf ${WRKSRC}/texmf/fonts/map/dvips/tetex
	rm -f ${WRKSRC}/texmf/web2c/fmtutil.cnf
	rm -f ${WRKSRC}/texmf/web2c/mktex.opt
	rm -f ${WRKSRC}/texmf/web2c/mktexdir
	rm -f ${WRKSRC}/texmf/web2c/mktexdir.opt
	rm -f ${WRKSRC}/texmf/web2c/mktexnam
	rm -f ${WRKSRC}/texmf/web2c/mktexnam.opt
	rm -f ${WRKSRC}/texmf/web2c/mktexupd
	rm -f ${WRKSRC}/texmf/web2c/texmf.cnf
	rm -f ${WRKSRC}/texmf/web2c/updmap.cfg
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

do-install:
.for texmf in texmf texmf-dist
	cd ${WRKSRC}/${texmf} && pax -wrpm * ${DESTDIR}${PREFIX}/share/${texmf}
.endfor

.include "../../mk/bsd.pkg.mk"
