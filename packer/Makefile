# $NetBSD$

PKGNAME=	packer-1.8.1
DISTNAME=	packer-${GITHUB_TAG}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_PROJECT=	packer
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://www.packer.io/
COMMENT=	Tool for creating identical machine images for multiple platforms
LICENSE=	mpl-2.0

EXTRACT_USING=	bsdtar

GO_VERSION_DEFAULT=	116
.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS+=	bin

.include "go-modules.mk"

GO_BUILD_PATTERN=	.
CHECK_RELRO_SKIP+=	bin/packer

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/packer ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
