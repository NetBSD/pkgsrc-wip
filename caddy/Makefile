# $NetBSD$

DISTNAME=	caddy-20170530
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mholt/}
GITHUB_TAG=	20a047f

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=mholt/caddy/}
COMMENT=	general-purpose web server
LICENSE=	apache-2.0

GO_DIST_BASE=	caddy-${GITHUB_TAG}*
GO_SRCPATH=	github.com/mholt/caddy
GO_BUILD_PATTERN= ${GO_SRCPATH}/caddy

EXTRACT_USING=		bsdtar

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/caddy ${DESTDIR}${PREFIX}/bin

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
