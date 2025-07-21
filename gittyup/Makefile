# $NetBSD$

DISTNAME=	gittyup_v1.4.0
PKGNAME=	${DISTNAME:S/_v/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Murmele/}
GITHUB_PROJECT=	Gittyup
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Murmele/Gittyup/
COMMENT=	Git GUI
LICENSE=	mit

WRKSRC=		${WRKDIR}/Gittyup-gittyup_v1.4.0
USE_LANGUAGES=	c c++
USE_TOOLS+=	git:run pkg-config

#option(USE_SYSTEM_QT "Don't copy QT files into the installation directory" OFF)
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_CMARK=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_GIT=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_HUNSPELL=ON
# as of 1.4.0: needs head of development branch
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_LIBGIT2=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_LIBSSH2=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_LUA=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_OPENSSL=ON

GITHUB_SUBMODULES+=	Murmele		libgit2		1d216661114e4072c8c35c852293774128083c82	dep/libgit2/libgit2
GITHUB_SUBMODULES+=	ScintillaOrg	lexilla		82b21cd1348366a7dc25d57c6de532968da40541	dep/scintilla/lexilla
GITHUB_SUBMODULES+=	orbitalquark	scintillua	33d0e3433a2046c1077f6b33fc801caf6bfac7a9	dep/scintilla/scintillua
GITHUB_SUBMODULES+=	kuba--		zip		d7a2252a537926cbdef8512741a322a183fcfd09	test/dep/zip

.include "../../devel/cmake/build.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/lua53/buildlink3.mk"
#.include "../../security/libssh2/buildlink3.mk"
# for libgit2
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/cmark/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
