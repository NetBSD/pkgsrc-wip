# $NetBSD: Makefile,v 1.1 2015/03/12 21:15:31 tnn2 Exp $
#

DISTNAME=		go-backoff-20141124
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=cenkalti/}
GITHUB_PROJECT=		backoff
GITHUB_TAG=		9831e1e25c

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/cenkalti/backoff
COMMENT=		Exponential backoff algorithm in Go
LICENSE=		mit

GO_SRCPATH=		github.com/cenkalti/backoff
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
