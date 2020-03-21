# $NetBSD$
#

DISTNAME=		go-collectd
PKGNAME=		go-collectd-20150830
PKGREVISION=		12
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=collectd/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		a1cfcc9efe

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/collectd/go-collectd
COMMENT=		Go language bindings for collectd
LICENSE=		modified-bsd

GO_SRCPATH=		collectd.org
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
