# $NetBSD: Makefile,v 1.2 2015/03/12 21:11:14 tnn2 Exp $
#

DISTNAME=		go-fsnotify-1.2.0
GITHUB_PROJECT=		fsnotify
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=go-fsnotify/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fsnotify.org/
COMMENT=		File system notifications for Go
LICENSE=		modified-bsd

GO_SRCPATH=		github.com/go-fsnotify/fsnotify
GO_DIST_BASE=		${GITHUB_PROJECT}-${PKGVERSION_NOREV}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
