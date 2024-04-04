# $NetBSD$

GITHUB_PROJECT=	gitbutler
GITHUB_TAG=	release/0.10.29
DISTNAME=	0.10.29
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gitbutlerapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitbutler.com/
COMMENT=	GitButler version control client
LICENSE=	mit # two years after release

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

WRKSRC=         ${WRKDIR}/gitbutler-release-0.10.29

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
