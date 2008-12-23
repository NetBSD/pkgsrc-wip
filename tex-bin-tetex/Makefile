# $NetBSD: Makefile,v 1.3 2008/12/23 09:22:07 minskim Exp $
# TeX Live Revision 11589

DISTNAME=	bin-tetex
PKGNAME=	tex-bin-tetex-3.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	scripts and files originally written for or included in teTeX

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf/web2c/updmap.cfg \
		${PKG_SYSCONFDIR}/web2c/updmap.cfg

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf ${PKG_SYSCONFDIR}

.include "../../wip/kpathsea/texmf.mk"

post-extract:
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf* ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
