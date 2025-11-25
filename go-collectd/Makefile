# $NetBSD$
#

DISTNAME=		go-collectd-0.6.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=collectd/}
#GITHUB_PROJECT=	${DISTNAME}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/collectd/go-collectd
COMMENT=		Go language bindings for collectd
LICENSE=		modified-bsd

GO_SRCPATH=		collectd.org
GO_DIST_BASE=		${DISTNAME}

.include "go-modules.mk"

.include "../../sysutils/collectd/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
