# $NetBSD: Makefile,v 1.5 2022/09/17 11:03:56 leot Exp $

DISTNAME=	git-bug-0.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=MichaelMure/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MichaelMure/git-bug
COMMENT=	Distributed offline-first bug tracker embedded in git, with bridges
LICENSE=	gnu-gpl-v3

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/MichaelMure/git-bug/commands.GitCommit= \
			-X github.com/MichaelMure/git-bug/commands.GitLastTag=${GITHUB_TAG} \
			-X github.com/MichaelMure/git-bug/commands.GitExactTag=${GITHUB_TAG}'

.include "go-modules.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
