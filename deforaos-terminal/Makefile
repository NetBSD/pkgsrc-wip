# $NetBSD: Makefile,v 1.1 2013/03/05 00:53:36 khorben Exp $
#

DISTNAME=	Terminal-0.0.0
PKGNAME=	deforaos-terminal-0.0.0
CATEGORIES=	sysutils
MASTER_SITES=	https://www.defora.org/os/download/download/4281/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop terminal emulator

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

DEPENDS+=	xterm-[0-9]*:../../x11/xterm

CONFLICTS=	xfce4-terminal-[0-9]*

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/terminal.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/terminal.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
