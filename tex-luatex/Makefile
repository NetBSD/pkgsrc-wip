# $NetBSD: Makefile,v 1.1.1.1 2009/02/09 00:30:23 minskim Exp $
# TeX Live Revision 10592

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	LuaTeX basic definition package

DEPENDS+=	tex-cm-[0-9]*:../../wip/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../wip/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../wip/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../wip/tex-misc
DEPENDS+=	tex-pdftex-[0-9]*:../../wip/tex-pdftex
DEPENDS+=	tex-plain-[0-9]*:../../wip/tex-plain
DEPENDS+=	web2c-[0-9]*:../../print/web2c

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEX_FORMAT_NAMES+=	luatex

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive-tetex/format.mk"

post-extract:
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf* ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
