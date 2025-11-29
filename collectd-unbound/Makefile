# $NetBSD$

DISTNAME=		collectd-unbound
PKGNAME=		${DISTNAME}-20150830
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=falzm/}
GITHUB_PROJECT=		${DISTNAME}
#GITHUB_TAG=		e751f86301
GITHUB_TAG=		e751f863013753578f47d6528cea1b4f91a5f6c6

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/falzm/collectd-unbound
COMMENT=		Collectd plugin for submitting unbound statistics
LICENSE=		modified-bsd

GO_SRCPATH=		github.com/falzm/collectd-unbound
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

DEPENDS+=		go-collectd-[0-9]*:../../wip/go-collectd
DEPENDS+=		collectd-[0-9]*:../../sysutils/collectd

#.include "../../wip/go-collectd/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
