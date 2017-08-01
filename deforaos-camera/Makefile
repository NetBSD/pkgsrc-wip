# $NetBSD: Makefile,v 1.4 2014/03/05 08:38:20 khorben Exp $
#

DISTNAME=	Camera-0.1.0
PKGNAME=	deforaos-camera-0.1.0
CATEGORIES=	graphics
MASTER_SITES=	https://www.defora.org/os/download/download/4320/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop camera
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/camera.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/camera.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/gallery.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gallery.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
