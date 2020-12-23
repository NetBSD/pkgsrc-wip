# $NetBSD$

DISTNAME=	libaudec-0.2.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=zrythm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dressupgeekout@gmail.com
COMMENT=	Wrapper library over minimp3, sndfile and libsamplerate
LICENSE=	gnu-gpl-v3 # XXX actually it's Affero v3

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
