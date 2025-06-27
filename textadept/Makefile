# $NetBSD$

DISTNAME=	textadept_12.7
PKGNAME=	textadept-12.7
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=orbitalquark/}
GITHUB_PROJECT=	textadept
GITHUB_TAG=	refs/tags/textadept_12.7
EXTRACT_SUFX=	.zip

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://github.com/orbitalquark/textadept/
COMMENT=	Cross-platform text editor for programmers
LICENSE=	mit

WRKSRC=		${WRKDIR}/textadept-textadept_12.7

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DGTK3=ON

# Distfiles with readable names
DISTFILES= \
	${DEFAULT_DISTFILES} \
	scintilla556.tgz \
	scinterm_5.5.zip \
	scintillua_6.5.zip \
	lua-5.4.7.tar.gz \
	lpeg-1.1.0.tar.gz \
	v1_8_0.zip \
	1.0.zip \
	t20240619.tar.gz \
	libtermkey-0.22.tar.gz \
	v14.2.5.zip \
	v3.4.0.zip

# Download URLs
SITES.scintilla556.tgz=		https://www.scintilla.org/
SITES.scinterm_5.5.zip=		https://github.com/orbitalquark/scinterm/archive/
SITES.scintillua_6.5.zip=	https://github.com/orbitalquark/scintillua/archive/
SITES.lua-5.4.7.tar.gz=		https://www.lua.org/ftp/
SITES.lpeg-1.1.0.tar.gz=	https://www.inf.puc-rio.br/~roberto/lpeg/
SITES.v1_8_0.zip=		https://github.com/keplerproject/luafilesystem/archive/
SITES.1.0.zip=			https://github.com/orbitalquark/lua-std-regex/archive/
SITES.t20240619.tar.gz=		\
	https://github.com/ThomasDickey/cdk-snapshots/archive/refs/tags/
SITES.libtermkey-0.22.tar.gz=	https://www.leonerd.org.uk/code/libtermkey/
SITES.v14.2.5.zip=		https://github.com/DaanDeMeyer/reproc/archive/refs/tags/
SITES.v3.4.0.zip=		https://github.com/itay-grudev/SingleApplication/archive/refs/tags/

# Custom extract dirs for each
EXTRACT_DIR.scintilla556.tgz=		${WRKDIR}/scintilla-src
EXTRACT_DIR.scinterm_5.5.zip=		${WRKDIR}/scinterm-src
EXTRACT_DIR.scintillua_6.5.zip=		${WRKDIR}/scintillua-src
EXTRACT_DIR.lua-5.4.7.tar.gz=		${WRKDIR}/lua-src
EXTRACT_DIR.lpeg-1.1.0.tar.gz=		${WRKDIR}/lpeg-src
EXTRACT_DIR.v1_8_0.zip=			${WRKDIR}/lfs-src
EXTRACT_DIR.1.0.zip=			${WRKDIR}/regex-src
EXTRACT_DIR.t20240619.tar.gz=		${WRKDIR}/cdk-src
EXTRACT_DIR.libtermkey-0.22.tar.gz=	${WRKDIR}/termkey-src
EXTRACT_DIR.v14.2.5.zip=		${WRKDIR}/reproc-src
EXTRACT_DIR.v3.4.0.zip=			${WRKDIR}/singleapp-src

# Symlink them into CMake's expected _deps folder
pre-configure:
	${MKDIR} ${WRKSRC}/cmake-pkgsrc-build/_deps
	${LN} -sf ${WRKDIR}/scintilla-src/scintilla	${WRKSRC}/cmake-pkgsrc-build/_deps/scintilla-src
	${LN} -sf ${WRKDIR}/scinterm-src	${WRKSRC}/cmake-pkgsrc-build/_deps/scinterm-src
	${LN} -sf ${WRKDIR}/scintillua-src	${WRKSRC}/cmake-pkgsrc-build/_deps/scintillua-src
	${LN} -sf ${WRKDIR}/lua-src			${WRKSRC}/cmake-pkgsrc-build/_deps/lua-src
	${LN} -sf ${WRKDIR}/lpeg-src		${WRKSRC}/cmake-pkgsrc-build/_deps/lpeg-src
	${LN} -sf ${WRKDIR}/lfs-src			${WRKSRC}/cmake-pkgsrc-build/_deps/lfs-src
	${LN} -sf ${WRKDIR}/regex-src		${WRKSRC}/cmake-pkgsrc-build/_deps/regex-src
	${LN} -sf ${WRKDIR}/cdk-src			${WRKSRC}/cmake-pkgsrc-build/_deps/cdk-src
	${LN} -sf ${WRKDIR}/termkey-src		${WRKSRC}/cmake-pkgsrc-build/_deps/termkey-src
	${LN} -sf ${WRKDIR}/reproc-src		${WRKSRC}/cmake-pkgsrc-build/_deps/reproc-src
	${LN} -sf ${WRKDIR}/singleapp-src/SingleApplication-3.4.0	${WRKSRC}/cmake-pkgsrc-build/_deps/singleapp-src

.include "../../lang/lua/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
