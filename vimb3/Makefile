# $NetBSD$

DISTNAME=	vimb-${GITHUB_TAG}
PKGNAME=	${DISTNAME:S/vimb/vimb3/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}
GITHUB_PROJECT=	vimb
GITHUB_TAG=	3.2.0

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

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
.include "../../mk/bsd.pkg.mk"
