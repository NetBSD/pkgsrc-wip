# $NetBSD: Makefile,v 1.1.1.1 2009/01/05 18:59:04 minskim Exp $
# TeX Live Revision 11613

DISTNAME=	bin-texlive
PKGNAME=	tex-${DISTNAME}-2008
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Executables and files maintained as part of TeX Live

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf/fmtutil/fmtutil-hdr.cnf \
		${PKG_SYSCONFDIR}/web2c/fmtutil.cnf
CONF_FILES+=	${PREFIX}/share/texmf/web2c/updmap-hdr.cfg \
		${PKG_SYSCONFDIR}/web2c/updmap.cfg

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/kpathsea/texmf.mk"

post-extract:
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf* ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
