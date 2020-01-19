# $NetBSD: Makefile,v 1.22 2020/01/10 13:32:18 bsiegert Exp $
#

DISTNAME=		lf-13
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=gokcehan/}
GITHUB_TAG=		r13

HOMEPAGE=		https://${GO_SRCPATH}
COMMENT=		Terminal file manager
LICENSE=		2-clause-bsd

#GO_SRCPATH=		github.com/gokcehan/lf
# GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

GO_MODULE=		yes

.include "../../devel/go-termbox/buildlink3.mk"
.include "../../wip/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
