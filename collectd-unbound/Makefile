# $NetBSD$

DISTNAME=		collectd-unbound-20170630
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=falzm/}
GITHUB_TAG=		300a1131368e717d8c57509a2ea3619372b4004a

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/falzm/collectd-unbound
COMMENT=		Collectd plugin for submitting unbound statistics
LICENSE=		modified-bsd

post-extract:
	${CP} ${FILESDIR}/go* ${WRKSRC}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
