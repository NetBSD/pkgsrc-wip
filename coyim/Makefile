# $NetBSD$

DISTNAME=	coyim-0.3.11
MASTER_SITES=	${MASTER_SITE_GITHUB:=coyim/}
CATEGORIES=	chat
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/coyim/coyim
COMMENT=	Safe and secure chat client
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config gmake

GO_DIST_BASE=		${PKGNAME_NOREV}
GO_SRCPATH=		github.com/coyim/coyim
GO_BUILD_PATTERN=	${GO_SRCPATH}

MAKE_ENV+=	CGO_LDFLAGS_ALLOW=".*"
MAKE_ENV+=	CGO_CFLAGS_ALLOW=".*"
MAKE_ENV+=	CGO_CXXFLAGS_ALLOW=".*"
MAKE_ENV+=	CGO_CPPFLAGS_ALLOW=".*"

CHECK_PORTABILITY_SKIP+=	build/mac-bundle/coyim-launcher.sh

COYIM_ICON=		coyim.png
COYIM_ICON_SRC=		${WRKSRC}/build/mac-bundle/coy.iconset/icon_32x32@2x.png
COYIM_DESKTOP_SAMPLE=	${WRKSRC}/build/coyim.desktop.sample
COYIM_DESKTOP=		${WRKSRC}/build/coyim.desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps

post-build:
	${CP} ${COYIM_DESKTOP} ${COYIM_DESKTOP_SAMPLE}
	${SED}  -e '/^#/d' \
		-e '/^$$/d' \
		< ${COYIM_DESKTOP_SAMPLE} \
		> ${COYIM_DESKTOP}
	${ECHO} "Exec=${PREFIX}/bin/coyim" >> ${COYIM_DESKTOP}
	${ECHO} "Icon=${COYIM_ICON}" >> ${COYIM_DESKTOP}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/coyim ${DESTDIR}${PREFIX}/bin

post-install:
	${INSTALL_DATA} ${COYIM_DESKTOP} ${DESTDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${COYIM_ICON_SRC} ${DESTDIR}${PREFIX}/share/pixmaps/${COYIM_ICON}

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.31.13
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=		pango>=1.22.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.1.93
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=		gtk3+>=3.1.9
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/go-golang-lru/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
