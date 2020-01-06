# $NetBSD$

GITHUB_PROJECT=	mle
DISTNAME=	v1.4.2
PKGNAME=	mle-1.4.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=adsr/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/adsr/mle/
COMMENT=	Termbox-based texteditor
LICENSE=	apache-2.0
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/mle-1.4.2

MAKE_FLAGS+=	prefix=${PREFIX}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

# \todo we should be able to use filename transformation here?
SUBST_CLASSES+=		lua
SUBST_MESSAGE.lua=	rewrite lua directory directives
SUBST_FILES.lua=	mle.h
SUBST_SED.lua=		-e 's,lua5.3/lualib.h,lua-5.3/lualib.h,g'
SUBST_SED.lua+=		-e 's,lua5.3/lua.h,lua-5.3/lua.h,g'
SUBST_SED.lua+=		-e 's,lua5.3/lauxlib.h,lua-5.3/lauxlib.h,g'
SUBST_STAGE.lua=	pre-build

pre-install:
	cd ${WRKSRC} && ${INSTALL_DATA} mle.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/lua53/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../wip/termbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
