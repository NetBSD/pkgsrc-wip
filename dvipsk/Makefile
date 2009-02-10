# $NetBSD: Makefile,v 1.1.1.1 2009/02/10 20:08:44 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	dvipsk-5.97
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.radicaleye.com/dvips.html
COMMENT=	DVI-to-PostScript translator

EXTRACT_ELEMENTS=	${DISTNAME}/texk/dvipsk \
			${DISTNAME}/texk/make \
			${DISTNAME}/texk/install.sh \
			${DISTNAME}/texk/mkinstalldirs

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	teTeX-bin-[0-9]*
DEPENDS+=	texlive-tetex-[0-9]*:../../print/texlive-tetex

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvipsk

FIND_PREFIX:=	TETEX_PREFIX=texlive-tetex
.include "../../mk/find-prefix.mk"

MAKE_ENV+=	KPATHSEA_PREFIX=${BUILDLINK_PREFIX.kpathsea}
MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q} \
		kpathsea_parent=${BUILDLINK_PREFIX.kpathsea}/include \
		kpathsea_srcdir=${BUILDLINK_PREFIX.kpathsea}/include/kpathsea \
		kpathsea=${BUILDLINK_PREFIX.kpathsea}/lib/libkpathsea.la

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dvips/config
CONF_FILES=	${PREFIX}/share/texmf/dvips/config/config.ps \
		${PKG_SYSCONFDIR}/dvips/config/config.ps

BUILD_DEFS+=		PAPERSIZE
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}

INSTALLATION_DIRS+=	share/texmf/dvips/config

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/kpathsea/buildlink3.mk"

post-build:
	${MKDIR} ${WRKSRC}/texmf
	env TFC_TEXMFCONFIG=${WRKSRC}/texmf \
		configPsFile=${WRKSRC}/config.ps \
		${TETEX_PREFIX}/bin/texconfig dvips paper ${LOWER_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texmf/dvips/config/config.ps \
		${DESTDIR}${PREFIX}/share/texmf/dvips/config

.include "../../mk/bsd.pkg.mk"
