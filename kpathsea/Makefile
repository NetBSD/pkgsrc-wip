# $NetBSD: Makefile,v 1.2 2008/11/23 20:42:18 minskim Exp $

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

SUBST_CLASSES+=		texmfdir
SUBST_MESSAGE.texmfdir=	Setting texmf directories.
SUBST_STAGE.texmfdir=	pre-configure
SUBST_FILES.texmfdir=	texmf.cnf
SUBST_SED.texmfdir=	-e 's,@TEXMFLOCAL@,${TEXMFLOCAL},' \
			-e 's,@VARBASE@,${VARBASE},' \
			-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'

PKG_SYSCONFSUBDIR=	texmf

BUILD_DEFS+=		TEXMFLOCAL
TEXMFLOCAL?=		${PREFIX}/share/texmf-local
FILES_SUBST+=		TEXMFLOCAL=${TEXMFLOCAL}

OWN_DIRS+=		${TEXMFLOCAL} ${VARBASE}/lib/texmf
INSTALLATION_DIRS+=	share/doc/texmf share/texmf-dist

.include "../../mk/bsd.pkg.mk"
