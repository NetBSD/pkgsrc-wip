# $NetBSD: Makefile,v 1.1.1.1 2008/11/18 03:04:35 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	kpathsea-3.5.7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/kpathsea/
COMMENT=	Library to do path searching

CONFLICTS+=	teTeX-bin-[0-9]*

EXTRACT_ELEMENTS=	${DISTNAME}/texk

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/kpathsea

MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}

.include "../../mk/bsd.pkg.mk"
