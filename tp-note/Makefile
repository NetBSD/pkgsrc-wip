# $NetBSD: Makefile,v 1.80 2024/06/24 08:36:36 pin Exp $

DISTNAME=	tp-note-1.24.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITLAB:=getreu/}
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://blog.getreu.net/projects/tp-note/
COMMENT=	Minimalistic note taking and template system
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/tp-note-v1.24.4-9e550fb8b3c7ec5ba215fc0ba66eda70b609c079

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

RUST_REQ=       1.77.2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/pixmaps

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tpnote \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/man1/tpnote.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/assets/tpnote.svg  \
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
