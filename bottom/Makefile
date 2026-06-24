# $NetBSD: Makefile,v 1.37 2024/08/29 07:37:41 fox Exp $

DISTNAME=	bottom-0.14.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ClementTsang/}
GITHUB_TAG=	0.14.1

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://bottom.pages.dev/
COMMENT=	Yet another cross-platform graphical process/system monitor.
LICENSE=	mit

RUST_REQ=	1.95.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1 \
			share/bash-completion/completions \
			share/fish/vendor_completions.d \
			share/zsh/site-functions

# Build manpages and shell completion
MAKE_ENV+=	BTM_GENERATE=true

GEN_DIR=        ${WRKDIR}/${PKGBASE}-${GITHUB_TAG}/target/tmp/bottom

post-install:
	${INSTALL_MAN} ${GEN_DIR}/manpage/btm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${GEN_DIR}/completion/btm.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/btm
	${INSTALL_DATA} ${GEN_DIR}/completion/btm.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${GEN_DIR}/completion/_btm     ${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
