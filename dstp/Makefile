# $NetBSD$

GITHUB_TAG=		refs/tags/v${PKGVERSION_NOREV}
DISTNAME=		dstp-0.3.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=ycd/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ycd/dstp/
COMMENT=		Run common networking tests against your site
LICENSE=		mit

USE_LANGUAGES=		# none

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

DEPENDS+=		go-tools-[0-9]*:../../devel/go-tools

GO_MODULE_FILES+=	github.com/fatih/color/@v/v1.13.0.mod
GO_MODULE_FILES+=	github.com/fatih/color/@v/v1.13.0.zip
GO_MODULE_FILES+=	github.com/go-ping/ping/@v/v0.0.0-20211014180314-6e2b003bffdd.mod
GO_MODULE_FILES+=	github.com/go-ping/ping/@v/v0.0.0-20211014180314-6e2b003bffdd.zip
GO_MODULE_FILES+=	github.com/google/uuid/@v/v1.2.0.mod
GO_MODULE_FILES+=	github.com/google/uuid/@v/v1.2.0.zip
GO_MODULE_FILES+=	github.com/mattn/go-colorable/@v/v0.1.9.mod
GO_MODULE_FILES+=	github.com/mattn/go-colorable/@v/v0.1.9.zip
GO_MODULE_FILES+=	github.com/mattn/go-isatty/@v/v0.0.12.mod
GO_MODULE_FILES+=	github.com/mattn/go-isatty/@v/v0.0.14.mod
GO_MODULE_FILES+=	github.com/mattn/go-isatty/@v/v0.0.14.zip
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20210316092652-d523dce5a7f4.mod
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20210316092652-d523dce5a7f4.zip
GO_MODULE_FILES+=	golang.org/x/sync/@v/v0.0.0-20210220032951-036812b2e83c.mod
GO_MODULE_FILES+=	golang.org/x/sync/@v/v0.0.0-20210220032951-036812b2e83c.zip
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20210630005230-0f9fa26af87c.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20210630005230-0f9fa26af87c.zip
GO_MODULE_FILES+=	golang.org/x/term/@v/v0.0.0-20201126162022-7de9c90e9dd1.mod
GO_MODULE_FILES+=	golang.org/x/term/@v/v0.0.0-20201126162022-7de9c90e9dd1.zip

.include "../../devel/go-sys/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../textproc/go-text/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
