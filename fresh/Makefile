# $NetBSD$

DISTNAME=	fresh-0.4.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=sinelaw/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sinelaw/fresh/
COMMENT=	Terminal-based IDE and text editor with zero configuration
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

CARGO_INSTALL_ARGS=	install --path crates/fresh-editor --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

# Fix lzma-sys vendored xz-5.2 build on NetBSD: the vendored config.h only
# defines HAVE_CLOCK_GETTIME for __sun, so the gettimeofday() fallback is
# used. But _POSIX_C_SOURCE=199506L hides gettimeofday() on NetBSD, and
# clock_gettime() works fine (and avoids the issue entirely).
# Upstream pr submitted.

post-extract:
	sed -i 's/#if defined(__sun)/#if defined(__sun) || defined(__NetBSD__)/' ${CARGO_VENDOR_DIR}/lzma-sys-0.1.20/config.h

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
