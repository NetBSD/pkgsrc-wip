# $NetBSD: Makefile,v 1.2 2009/01/25 08:32:03 minskim Exp $
# TeX Live Revision 7621

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2008.7621
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Computer Modern fonts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEX_MIXEDMAP_FILES+=	cmother-bsr.map
TEX_MIXEDMAP_FILES+=	cmtext-bsr-interpolated.map
TEX_MIXEDMAP_FILES+=	cmtext-bsr.map

.include "../../print/kpathsea/texmf.mk"
.include "../../wip/texlive-tetex/map.mk"

post-extract:
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf* ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
