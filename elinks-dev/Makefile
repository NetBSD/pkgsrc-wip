# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	elinks-0.18.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkd77/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkd77/elinks/
COMMENT=	Feature-rich text mode web browser
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

WRKSRC=	${WRKDIR}/${DISTNAME}

MESON_ARGS+=	-Dlibcss=false
MESON_ARGS+=	-Dgpm=false
LDFLAGS+=	-lexecinfo

REPLACE_PERL+=		doc/tools/help2xml

.include "../../lang/python/tool.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../devel/tre/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
