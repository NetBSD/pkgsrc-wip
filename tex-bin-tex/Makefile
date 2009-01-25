# $NetBSD: Makefile,v 1.1.1.1 2009/01/25 19:17:08 minskim Exp $
# TeX Live Revision 10592

DISTNAME=	bin-tex
PKGNAME=	tex-${DISTNAME}-2008.10592
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Plain TeX format

DEPENDS+=	tex-bin-kpathsea-[0-9]*:../../wip/tex-bin-kpathsea
DEPENDS+=	tex-cm-[0-9]*:../../wip/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../wip/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../wip/tex-misc
DEPENDS+=	tex-plain-[0-9]*:../../wip/tex-plain
DEPENDS+=	web2c-[0-9]*:../../wip/web2c

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEX_FORMAT_NAMES+=	tex

.include "../../print/kpathsea/texmf.mk"
.include "../../wip/texlive-tetex/format.mk"

post-extract:
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf* ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
