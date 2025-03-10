# $NetBSD$

DISTNAME=	alacritty-0.16.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=alacritty/}
GITHUB_TAG=	03c2907b44b4189aac5fdeaea331f5aab5c7072e

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://alacritty.org/
COMMENT=	Cross-platform, GPU-accelerated terminal emulator
LICENSE=	apache-2.0

TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=		scdoc-[0-9]*:../../textproc/scdoc

.include "cargo-depends.mk"

WRKSRC=			${WRKDIR}/alacritty-03c2907b44b4189aac5fdeaea331f5aab5c7072e

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config	# for fontconfig-sys

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.freetype2}/lib
.endif

.if ${OPSYS} == "NetBSD" && exists(${X11BASE}/lib/X11/locale/lib/common/xlcUTF8Load.so)
# This works around XIM errors when RTLD local-binding libX11.
# https://mail-index.netbsd.org/tech-x11/2021/07/12/msg002222.html
# https://mail-index.netbsd.org/source-changes/2021/07/13/msg130884.html
SUBST_CLASSES+=		rtld
SUBST_MESSAGE.rtld=	amend RTLD_GLOBAL
SUBST_STAGE.rtld=	pre-configure
SUBST_FILES.rtld=	../vendor/x11-dl-*/src/link.rs
SUBST_SED.rtld=		-e 's,libc::RTLD_LAZY,& | libc::RTLD_GLOBAL,g'
.endif

# The xcb crate depends on any version of python 3.
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	bin share/applications ${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5 share/icons/hicolor/scalable/apps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/alacritty \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/extra/linux/Alacritty.desktop \
                 ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/extra/logo/alacritty-term.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps

post-install:
	scdoc < ${WRKSRC}/extra/man/alacritty-msg.1.scd > ${WRKSRC}/extra/man/alacritty-msg.1
	scdoc < ${WRKSRC}/extra/man/alacritty.1.scd > ${WRKSRC}/extra/man/alacritty.1
	scdoc < ${WRKSRC}/extra/man/alacritty.5.scd > ${WRKSRC}/extra/man/alacritty.5
	scdoc < ${WRKSRC}/extra/man/alacritty-bindings.5.scd > ${WRKSRC}/extra/man/alacritty-bindings.5
	${INSTALL_MAN} ${WRKSRC}/extra/man/alacritty.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alacritty.1
	${INSTALL_MAN} ${WRKSRC}/extra/man/alacritty-msg.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alacritty-msg.1
	${INSTALL_MAN} ${WRKSRC}/extra/man/alacritty.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/alacritty.5
	${INSTALL_MAN} ${WRKSRC}/extra/man/alacritty-bindings.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/alacritty-bindings.5

# This package is kept up-to-date for personal use and I don't need Wayland.
# If someone wishes to build it with Wayland support comment out the these lines.
# If someone wishes to build only for Wayalnd use, replace 'x11' with 'wayland'.
CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		x11

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
