# $NetBSD: Makefile,v 1.4 2016/10/17 11:47:12 joerg Exp $

GITHUB_PROJECT=	beampy
GITHUB_TAG=	6994aa6e66f77b56e0bf6c1fa4cdd94e106e7b84
# Upstream does not generate tags
DISTNAME=	beampy-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hchauvet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hchauvet/beampy
COMMENT=	Tool to create slide-show in SVG
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar

WRKSRC=		${WRKDIR}/beampy-${GITHUB_TAG}/

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

DEPENDS+=	dvisvgm-[0-9]*:../../wip/dvisvgm
DEPENDS+=	pdfjam-[0-9]*:../../print/pdfjam # pdfjoin
DEPENDS+=	inkscape-[0-9]*:../../graphics/inkscape
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

SUBST_CLASSES+=			ffmpeg3
SUBST_STAGE.ffmpeg3=		post-extract
SUBST_FILES.ffmpeg3+=		beampy/document.py
SUBST_SED.ffmpeg3=		-e "s,find_executable('ffmpeg'),find_executable('ffmpeg3'),"

.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
