# $NetBSD$

DISTNAME=	grafX2-2.4
CATEGORIES=	graphics
MASTER_SITES=	-https://gitlab.com/GrafX2/${GITLAB_PROJECT}/repository/${GITLAB_REV}/archive.tar.gz

HOMEPAGE=	http://grafx2.chez.com/
COMMENT=	Bitmap paint program suited for pixel art
LICENSE=	gnu-gpl-v2

GITLAB_PROJECT=	grafX2
GITLAB_TAG=	34166d75592b60a6d0c1f85f60029bc03cbe13f4
GITLAB_REV=	v${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_REV}-${GITLAB_TAG}/src

USE_TOOLS=	pkg-config gmake

MAKE_FLAGS+=	prefix=${PREFIX}
CFLAGS+=	-DPREFIX=\"${PREFIX}\"

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
