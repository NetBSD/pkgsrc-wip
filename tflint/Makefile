# $NetBSD$

DISTNAME=	tflint-0.44.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=terraform-linters/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/terraform-linters/tflint
COMMENT=	Pluggable Terraform Linter
LICENSE=	mpl-2.0

do-install:
	${INSTALL} ${WRKDIR}/.gopath/bin/tflint ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
