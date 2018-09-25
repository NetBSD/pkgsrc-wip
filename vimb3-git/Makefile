# $NetBSD: Makefile,v 1.21 2015/08/22 12:26:27 leot1990 Exp $

DISTNAME=	vimb-3.2.0
PKGNAME=	${DISTNAME:S/vimb/vimb3/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	vimb
GIT_REPO.vimb=		git://github.com/fanglingsu/vimb.git
WRKSRC=			${WRKDIR}/vimb

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# needed for LOCK_* macros in <fcntl.h>

EGDIR=		${PREFIX}/share/examples/vimb

MAKE_FLAGS+=	EXAMPLEPREFIX="${DESTDIR}${EGDIR}"
MAKE_FLAGS+=	MANPREFIX="${DESTDIR}${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	RUNPREFIX="${PREFIX}"

# Avoid conflicts with www/vimb
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/vimb ${DESTDIR}${PREFIX}/bin/vimb3
	${MV} ${DESTDIR}${PREFIX}/share/applications/vimb.desktop ${DESTDIR}${PREFIX}/share/applications/vimb3.desktop
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vimb.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vimb3.1

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
