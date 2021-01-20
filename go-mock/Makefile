# $NetBSD$

DISTNAME=	go-mock-1.4.4
GITHUB_PROJECT=	mock
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/golang/mock
COMMENT=	GoMock is a mocking framework for the Go
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/golang/mock

USE_TOOLS+=	bash:run

REPLACE_BASH+=	ci/check_go_fmt.sh ci/check_go_generate.sh \
		ci/check_go_lint.sh ci/check_go_mod.sh

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../textproc/go-goldmark/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
