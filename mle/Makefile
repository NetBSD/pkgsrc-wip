# $NetBSD$

DISTNAME=	mle-1.7.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=adsr/}
GITHUB_RELEASE=	v1.7.2
GITHUB_PROJECT=	mle

MAINTAINER=	ktnb@posteo.net
HOMEPAGE=	https://github.com/adsr/mle/
COMMENT=	Termbox-based text editor
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	prefix=${PREFIX}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		lua
SUBST_MESSAGE.lua=	rewrite lua directory directives
SUBST_FILES.lua=	mle.h
SUBST_SED.lua=		-e 's,lua5.4/lualib.h,lua-5.4/lualib.h,g'
SUBST_SED.lua+=		-e 's,lua5.4/lua.h,lua-5.4/lua.h,g'
SUBST_SED.lua+=		-e 's,lua5.4/lauxlib.h,lua-5.4/lauxlib.h,g'
SUBST_STAGE.lua=	pre-build

SUBST_CLASSES+=		makefile
SUBST_MESSAGE.makefile=	remove -v flag
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=		-e 's,install -v,install,g'
SUBST_STAGE.makefile=	pre-build

pre-install:
	cd ${WRKSRC} && ${INSTALL_MAN} mle.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
