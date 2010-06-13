# $NetBSD: Makefile,v 1.4 2010/06/13 22:47:13 thomasklausner Exp $
#

DISTNAME=	pdfmod-0.8
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pdfmod/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://live.gnome.org/PdfMod
COMMENT=	PDF Mod is a simple tool for modifying PDF documents
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALDIR=  yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/usr/pkg/lib/pdfmod

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../wip/hyena/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
