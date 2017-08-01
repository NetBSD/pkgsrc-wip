# $NetBSD: Makefile,v 1.5 2015/01/27 00:10:10 khorben Exp $
#

DISTNAME=	PDFViewer-0.0.1
PKGNAME=	deforaos-pdfviewer-0.0.1
CATEGORIES=	print
MASTER_SITES=	https://www.defora.org/os/download/download/3686/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop PDF viewer

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "options.mk"

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
