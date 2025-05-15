# $NetBSD: Makefile,v 1.5 2022/09/17 11:03:56 leot Exp $

DISTNAME=	git-bug-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=MichaelMure/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MichaelMure/git-bug
COMMENT=	Distributed offline-first bug tracker embedded in git, with bridges
LICENSE=	gnu-gpl-v3

#GO_BUILD_PATTERN+=	-ldflags ' \
#			-X github.com/MichaelMure/git-bug/commands.GitCommit= \
#			-X github.com/MichaelMure/git-bug/commands.GitLastTag=${GITHUB_TAG} \
#			-X github.com/MichaelMure/git-bug/commands.GitExactTag=${GITHUB_TAG}'

.include "go-modules.mk"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${DESTDIR}${PREFIX}/bin && ${RM} cmd completion doc
	${INSTALL_DATA} ${WRKSRC}/misc/completion/bash/git-bug ${DESTDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/misc/completion/fish/git-bug ${DESTDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/misc/completion/zsh/git-bug ${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
