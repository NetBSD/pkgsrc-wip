# $NetBSD: Makefile,v 1.4 2015/04/25 22:26:45 tnn2 Exp $

DISTNAME=	syncthing-inotify-0.6.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/syncthing/syncthing-inotify
COMMENT=	Inotify file watcher intended for use with Syncthing
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	go-[0-9]*:../../lang/go
DEPENDS+=	syncthing>=0.11.0:../../net/syncthing

MAKE_ENV+=	GOPATH=${PREFIX}/gopkg

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}\
		${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../wip/go-backoff/buildlink3.mk"
.include "../../wip/go-notify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
