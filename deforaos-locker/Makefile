# $NetBSD: Makefile,v 1.9 2014/06/26 12:24:32 khorben Exp $

DISTNAME=	Locker-0.2.2
PKGNAME=	deforaos-locker-0.2.2
CATEGORIES=	x11
MASTER_SITES=	https://www.defora.org/os/download/download/4329/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop screensaver

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/locker.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/locker.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/lockerctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lockerctl.1
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/locker.html ${DESTDIR}${PREFIX}/share/doc/html/Locker/locker.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/lockerctl.html ${DESTDIR}${PREFIX}/share/doc/html/Locker/lockerctl.html
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../wip/deforaos-panel/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
