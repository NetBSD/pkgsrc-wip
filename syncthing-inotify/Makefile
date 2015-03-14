# $NetBSD: Makefile,v 1.2 2015/03/14 08:35:32 thomasklausner Exp $

DISTNAME=	syncthing-inotify-0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/syncthing/syncthing-inotify
COMMENT=	Inotify file watcher intended for use with Syncthing
LICENSE=	mpl-2.0

BUILD_DEPENDS+=	go-[0-9]*:../../lang/go

MAKE_ENV+=	GOPATH=${PREFIX}/gopkg

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}\
		${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../wip/go-fsnotify/buildlink3.mk"
.include "../../wip/go-backoff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
