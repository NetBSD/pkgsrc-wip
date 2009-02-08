# $NetBSD: Makefile,v 1.1.1.1 2009/02/08 23:32:47 minskim Exp $
# TeX Live Revision 11868

DISTNAME=	pdftex
PKGNAME=	tex-${DISTNAME}-1.40.9
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeX extension for direct creation of PDF

DEPENDS+=	tex-bin-kpathsea-[0-9]*:../../print/tex-bin-kpathsea
DEPENDS+=	tex-cm-[0-9]*:../../wip/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../wip/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../wip/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../wip/tex-misc
DEPENDS+=	tex-plain-[0-9]*:../../wip/tex-plain

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEX_FORMAT_NAMES+=	pdftex

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive-tetex/format.mk"

post-extract:
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf* ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
