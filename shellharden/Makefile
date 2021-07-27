# $NetBSD$

DISTNAME=	shellharden-4.1.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=anordal/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	shells

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/anordal/shellharden/
COMMENT=	Shell script syntax highlighter and rewriter
LICENSE=	mpl-2.0

USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/shellharden ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
