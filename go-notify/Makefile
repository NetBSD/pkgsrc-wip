# $NetBSD: Makefile,v 1.1 2015/04/25 17:10:48 tnn2 Exp $

DISTNAME=		go-notify-20150316
GITHUB_PROJECT=         notify
CATEGORIES=             devel
MASTER_SITES=           ${MASTER_SITE_GITHUB:=rjeczalik/}
GITHUB_TAG=             9ae2c42a589ea0ee4761559fd5b2c4b747b4150f

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fsnotify.org/
COMMENT=		File system event notification library on steroids
LICENSE=		mit

GO_SRCPATH=		github.com/rjeczalik/notify
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
