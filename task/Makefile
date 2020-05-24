# $NetBSD$

PKGNAME=	task-2.8.1
DISTNAME=	task-${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-task/}
GITHUB_PROJECT=	task
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://taskfile.dev/
COMMENT=	Task-runner / simpler Make alternative written in Go
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/go-task/task/

INSTALLATION_DIRS+=	bin \
			share/bash-completion/completions \
			share/zsh/site-functions

do-build:
	${RUN} ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install \
		-ldflags '-X main.version=${PKGVERSION_NOREV}' -v ${GO_BUILD_PATTERN}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/task ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/completion/bash/task.bash \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/task
	${INSTALL_DATA} ${WRKSRC}/completion/zsh/_task \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_task

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
