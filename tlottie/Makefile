# $NetBSD$

DISTNAME=	tlottie-1.0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=dkaraush/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dkaraush/tlottie
COMMENT=	Pure-Rust Lottie animation renderer with C API
LICENSE=	mpl-2.0

CARGO_CRATE_DEPENDS+=	cfg-if-1.0.4
CARGO_CRATE_DEPENDS+=	dlmalloc-0.2.14
CARGO_CRATE_DEPENDS+=	foldhash-0.1.5
CARGO_CRATE_DEPENDS+=	hashbrown-0.15.5
CARGO_CRATE_DEPENDS+=	libc-0.2.189
CARGO_CRATE_DEPENDS+=	windows-link-0.2.1
CARGO_CRATE_DEPENDS+=	windows-sys-0.61.2

CARGO_FEATURES=	c-api

INSTALLATION_DIRS+=	lib include/tlottie

post-extract:
.for _crate in ${CARGO_CRATE_DEPENDS}
	${MKDIR} ${CARGO_VENDOR_DIR}/${_crate}
	tar -xzf ${_DISTDIR}/${_crate}.crate -C ${CARGO_VENDOR_DIR}/${_crate} --strip-components 1
.endfor

do-install:
	install -m 0755 ${WRKSRC}/target/release/libtlottie.so \
		${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/tlottie.h \
		${DESTDIR}${PREFIX}/include/tlottie/tlottie.h

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
