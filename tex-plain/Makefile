# $NetBSD: Makefile,v 1.1.1.1 2008/12/12 02:43:31 minskim Exp $
# TeX Live Revision 9267

DISTNAME=	plain
PKGNAME=	tex-plain-3.14159265
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	The Plain TeX format

CONFLICTS+=	teTeX-texmf-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

TEXMFDIRS=	${TEXMFDIST}

.include "../../wip/kpathsea/buildlink3.mk"

post-extract:
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC}/texmf-dist && \
		pax -rwpm * ${DESTDIR}${TEXMFDIST}

.include "../../mk/bsd.pkg.mk"
