# $NetBSD: Makefile,v 1.2 2023/04/27 08:26:38 wiz Exp $

DISTNAME=	tree-sitter-0.20.9
PKGNAME=	${DISTNAME:S/sitter/sitter-cli/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_PROJECT=	tree-sitter
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tree-sitter.github.io/
COMMENT=	Incremental parsing system for programming tools (CLI)
LICENSE=	mit

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
WASMTIME_REV=		fa6fcd946b8f6d60c2d191a1b14b9399e261a76d
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		wasmtime-${WASMTIME_REV}.tar.gz
SITES.wasmtime-${WASMTIME_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=bytecodealliance/}wasmtime/archive/${WASMTIME_REV}.tar.gz

INSTALLATION_DIRS=	bin

post-extract:
	mv ${WRKDIR}/wasmtime-* ${WRKDIR}/vendor
	${ECHO} '{"files":{}}' > ${WRKDIR}/vendor/wasmtime-fa6fcd946b8f6d60c2d191a1b14b9399e261a76d/.cargo-checksum.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tree-sitter \
		${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
