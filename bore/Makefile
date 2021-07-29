# $NetBSD$

DISTNAME=	bore-0.3.3
CATEGORIES=	net
MASTER_SITES=	-https://bitbucket.org/delan/nonymous/get/${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://crates.io/crates/bore
COMMENT=	DNS query tool
LICENSE=	isc

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/delan-nonymous-483b20757a1a/bore

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../target/release/bore ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bore.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
