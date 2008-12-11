# $NetBSD: Makefile,v 1.2 2008/12/11 01:10:39 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	texlive-tetex-2008
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Scripts included in teTeX

CONFLICTS+=	teTeX-bin-[0-9]*
DEPENDS+=	dialog>=1.0:../../misc/dialog

EXTRACT_ELEMENTS=	${DISTNAME}/texk

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/tetex

TEXMFDIRS=	${TEXMFMAIN}

.include "../../wip/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
