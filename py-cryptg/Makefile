# $NetBSD: Makefile,v 1.27 2022/01/10 18:27:55 wiz Exp $

DISTNAME=	cryptg-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cher-nov/}
GITHUB_PROJECT=	cryptg
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://pypi.org/project/cryptg/
COMMENT=	Telethon extension to provide cryptography for Telegram requests
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=0.11.4:../../devel/py-setuptools-rust

CARGO_WRKSRC=	${WRKSRC}/src/rust
USE_TOOLS+=	pkg-config
MAKE_ENV+=	CARGO_NET_OFFLINE=true
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-build:
	cd ${WRKSRC} && ${LN} -f -s src/rust/.cargo .cargo

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
