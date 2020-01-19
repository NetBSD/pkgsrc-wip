# $NetBSD$

# This is "0.8", which is unreleased. For
# convenient A -> B updating reasons as upstream
# will no longer have an 0.0.8 versions, this is
# named 0.0.8. Bbuilding 0.7.0 will fail on NetBSD.
DISTNAME=	zola-0.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=getzola/}
GITHUB_PROJECT=	zola
GITHUB_TAG=	9df946508076c4092be5ca5c6b04a21f804636a3

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://www.getzola.org/
COMMENT=	Static website generator
LICENSE=	mit

CARGO_CRATE_DEPENDS+=	\
	atty-0.2.11 \
	clap-2.33.0 \
	chrono-0.4.6 \
	lazy_static-1.1.0 \
	toml-0.4.1 \
	termcolor-1.0.4 \
	url-1.7.2 \
	actix-files-0.1.2 \
	actix-web-1.0.2 \
	notify-4.0.12 \
	ws-0.8.1 \
	ctrlc-3.1.3 \
	globset-0.4.3 \
	lazy_static-1.3.0 \
	serde-1.0.92 \
	serde_derive-1.0.92 \
	syntect-3.2.0 \
	toml-0.5.1 \
	image-0.21.2 \
	tera-1.0.0-beta.10

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo build --locked --frozen --release -j${_MAKE_JOBS_N}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/zola ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
