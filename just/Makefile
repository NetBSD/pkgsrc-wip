# $NetBSD$

DISTNAME=	just-1.53.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=casey/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/casey/just/
COMMENT=	Handy way to save and run project-specific commands
LICENSE=	cc0-1.0-universal

USE_LANGUAGES=	c

post-build: do-generate-manpage
.PHONY: do-generate-manpage
do-generate-manpage:
	${RUN} cd ${CARGO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} \
		./target/release/just --man > ${WRKSRC}/just.1

# Install the man page
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install: do-install-manpage
.PHONY: do-install-manpage
do-install-manpage:
	${INSTALL_MAN} ${WRKSRC}/just.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/just.1

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
