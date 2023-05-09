# $NetBSD: Makefile,v 1.1 2023/05/09 21:58:30 nikita Exp $

DISTNAME=	lpc55-0.2.1
CATEGORIES=	devel
MAINTAINER=	nikita@NetBSD.org
# release on github includes no Cargo.lock
MASTER_SITES=	https://static.crates.io/crates/lpc55/
EXTRACT_SUFX=	.crate

HOMEPAGE=	https://github.com/lpc55/lpc-host
COMMENT=	Host-side tooling to interact with LPC55 chips via the ROM bootloader
LICENSE=	apache-2.0 OR mit

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lpc55 ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
