# $NetBSD$

# XXX: Before updating this package please check
# XXX: <https://github.com/terraform-linters/tflint/discussions/1826> and if
# XXX: license changed.
# XXX: It would be nice to preserve a last mpl-2.0 version of this package so
# XXX: people can still use that one instead of the one under
# XXX: busl-1.1-license.

DISTNAME=	tflint-0.48.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=terraform-linters/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/terraform-linters/tflint
COMMENT=	Pluggable Terraform Linter
LICENSE=	mpl-2.0

# By default several other test binaries are installed, only tflint
# should be installed
do-install:
	${INSTALL} ${WRKDIR}/.gopath/bin/tflint ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
