# $NetBSD$

VERSION=	0.3.8
PKGVERSION=	${VERSION}
PKGNAME=	gokrazy-rsync-${VERSION}
CATEGORIES=	net
#MASTER_SITES=	${MASTER_SITE_GITHUB:=gokrazy/}
#GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

# Renaming the distfile to avoid potential conflicts with the original
# "tridge" rsync distfile. They both would download as
# 'rsync-$VERSION.tar.gz'.
DISTNAME=	${PKGNAME}
MASTER_SITES=	-https://github.com/gokrazy/rsync/archive/refs/tags/v${VERSION}.tar.gz

MAINTAINER=	tallirishllama@gmail.com
HOMEPAGE=	https://github.com/gokrazy/rsync/
COMMENT=	Rsync alternative written in Go
LICENSE=	modified-bsd

# Moving the work dir into a subdirectory to avoid conflicts with the
# original "tridge" rsync package in case a bulk build needs to build
# both.
WRKDIR=	${WRKOBJDIR}/gokrazy-rsync
WRKSRC=	${WRKDIR}/rsync-${VERSION}

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
