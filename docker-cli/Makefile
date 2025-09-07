# $NetBSD$

DISTNAME=	docker-cli-24.0.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=docker/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/docker/cli/
COMMENT=	Command-line tool for controlling Docker
LICENSE=	apache-2.0

GO_DIST_BASE=	cli-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/docker/cli

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/docker/cli/cli/version.Version=${PKGVERSION_NOREV} \
			-X github.com/docker/cli/cli/version.GitCommit= \
			-X github.com/docker/cli/cli/version.BuildTime= \
			-X github.com/docker/cli/cli/version.PlatformName='
GO_BUILD_PATTERN+=	${GO_SRCPATH}/...

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Honor plugins under PREFIX
SUBST_FILES.paths+=	cli-plugins/manager/manager_unix.go
SUBST_VARS.paths+=	PREFIX

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/completions

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/docker ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/bash/docker ${DESTDIR}${PREFIX}/share/bash-completion/completions
	# Already installed by shells/fish
	#${INSTALL_DATA} ${WRKSRC}/contrib/completion/fish/docker.fish ${DESTDIR}${PREFIX}/share/fish/completions

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
