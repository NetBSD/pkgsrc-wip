# $NetBSD$

PKGNAME=	cuelang-0.10.0
DISTNAME=	cue-${GITHUB_TAG}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=cue-lang/}
GITHUB_PROJECT=	cue
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://cuelang.org/
COMMENT=	Validate and define text-based and dynamic configuration
LICENSE=	apache-2.0

CONFLICTS+=	cue-[0-9]*

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN=	./cmd/cue

INSTALLATION_DIRS+=	bin

do-build:
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install \
		-ldflags '-s -w -X cuelang.org/go/cmd/cue/cmd.version=${PKGVERSION_NOREV}' -v ${GO_BUILD_PATTERN}

do-install:
	${RUN} cd ${WRKDIR}/.gopath && [ ! -d bin ] || ${PAX} -rw bin ${DESTDIR}${PREFIX}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
