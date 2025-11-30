# $NetBSD$

DISTNAME=		collectd-unbound
PKGNAME=		${DISTNAME}-20150830
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=falzm/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		300a1131368e717d8c57509a2ea3619372b4004a

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/falzm/collectd-unbound
COMMENT=		Collectd plugin for submitting unbound statistics
LICENSE=		modified-bsd

DEPENDS+=		go-collectd-[0-9]*:../../wip/go-collectd
DEPENDS+=		collectd-[0-9]*:../../sysutils/collectd

post-extract:
	${CP} ${FILESDIR}/go* ${WRKSRC}

.include "go-modules.mk"

#.include "../../wip/go-collectd/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
