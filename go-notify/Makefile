# $NetBSD: Makefile,v 1.1 2015/04/25 17:10:48 tnn2 Exp $

DISTNAME=		go-notify-20150523
GITHUB_PROJECT=		notify
PKGREVISION=		12
CATEGORIES=		devel
#MASTER_SITES=		${MASTER_SITE_GITHUB:=rjeczalik/}
MASTER_SITES=		${MASTER_SITE_GITHUB:=zillode/}
GITHUB_TAG=		f06b1e3b795091f2e1414067b08e5f07332cdb05

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fsnotify.org/
COMMENT=		File system event notification library on steroids
LICENSE=		mit

GO_SRCPATH=		github.com/zillode/notify
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
