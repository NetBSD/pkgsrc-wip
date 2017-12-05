# $NetBSD$

DISTNAME=	upspin
PKGNAME= 	go-${DISTNAME}-05122017
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=upspin/}
GITHUB_TAG= 	860680cdc04e940ac98b8e333bc8fa033eb15f43
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://upspin.io/
COMMENT=	Secure, shared, distributed, information system
LICENSE=	modified-bsd

GO_SRCPATH= 	upspin.io
GO_BUILD_PATTERN= 	${GO_SRCPATH}/cmd/...
GO_DIST_BASE= 	${DISTNAME}-${GITHUB_TAG}

REPLACE_BASH= 	cmd/upspin/mkdoc.sh
REPLACE_BASH+= 	cmd/upspinfs/scripts/fstabfortest
REPLACE_BASH+= 	cmd/upspinfs/scripts/mount_darwin
REPLACE_BASH+= 	cmd/upspinfs/scripts/mount_linux

post-patch:
	${FIND} ${WRKSRC} -type f -name \*.orig -delete

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
