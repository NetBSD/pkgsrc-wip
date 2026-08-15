# $NetBSD$

DISTNAME=	${PKGBASE}-v${PKGVERSION_NOREV}
PKGNAME=	cq-cli-0.17.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla-ai/}
GITHUB_PROJECT=	cq
GITHUB_TAG=	refs/tags/cli/${DISTNAME:C/^.*-//}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://docs.mozilla.ai/cq
COMMENT=	Open standard for shared agent learning
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/cli
MAKE_ENV+=	CGO_ENABLED=0
USE_LANGUAGES=	# none

.include "go-modules.mk"

GO_BUILD_DATE_cmd=	${DATE} -u '+%Y-%m-%dT%H:%M:%SZ'
GOFLAGS=		-ldflags '-s -w \
			-X "github.com/mozilla-ai/cq/cli/internal/version.version=${PKGVERSION_NOREV}" \
			-X "github.com/mozilla-ai/cq/cli/internal/version.date=${GO_BUILD_DATE_cmd:sh}"'

INSTALLATION_DIRS+=	bin

post-build:
	${RUN} cd ${WRKDIR}/.gopath && mv ${GOPATH_BIN}/cli ${GOPATH_BIN}/cq

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
