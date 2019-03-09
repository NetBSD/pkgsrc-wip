# $NetBSD$

PKGNAME=	greybird-theme-3.22.10
DISTNAME=	Greybird-${PKGVERSION_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shimmerproject/}
EXTRACT_USING=	bsdtar

MAINTAINER=	robn@gmx.com
HOMEPAGE=	https://github.com/shimmerproject/Greybird/
COMMENT=	Desktop Suite for Xfce
LICENSE=	cc-by-sa-v3.0 OR gnu-gpl-v2

GITHUB_PROJECT=	Greybird
GITHUB_TAG=	v${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake

BUILD_DEPENDS+=	sassc-[0-9]*:../../www/sassc
DEPENDS+=	gtk2-engines-murrine-[0-9]*:../../x11/gtk2-engines-murrine

post-extract:
	find ${WRKSRC} -type d -print0 | xargs -0 chmod 755
	find ${WRKSRC} -type f -perm 664 -print0 | xargs -0 chmod 644

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
