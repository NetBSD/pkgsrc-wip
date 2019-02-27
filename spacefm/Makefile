# $NetBSD: Makefile,v 0.3 2018/09/11 14:44:10 andyb Exp $


GITHUB_PROJECT=	spacefm
DISTNAME=	1.0.6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=IgnorantGuru/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	andyb@m42.one
HOMEPAGE=	https://github.com/IgnorantGuru/spacefm/
COMMENT=	SpaceFM Filemanager
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/spacefm-1.0.6
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
#CC=		gcc $(pkg-config --cflags gtk+-3.0) $(pkg-config --cflags glib-2.0) $(pkg-config --cflags gdk)
#CC=		gcc -I/usr/pkg/include/gtk-3.0/ -I/usr/pkg/include/glib/glib-2.0/

USE_TOOLS+=	intltool msgfmt pkg-config automake autoconf

DEPENDS+=	libX11-[0-9]*:../../x11/libX11
DEPENDS+=	hal-[0-9]*:../../sysutils/hal
DEPENDS+=	desktop-file-utils-[0-9]*:../../sysutils/desktop-file-utils
DEPENDS+=	shared-mime-info-[0-9]*:../../databases/shared-mime-info
DEPENDS+=	ffmpegthumbnailer-[0-9]*:../../multimedia/ffmpegthumbnailer

#edit me
export LIBUDEV_CFLAGS=	-I/usr/lib/pkgconfig/
export LIBUDEV_LIBS=	/usr/lib/pkgconfig/
#edit me

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../sysutils/libfm/buildlink3.mk"
.include "../../sysutils/libfm-extra/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../multimedia/ffmpegthumbnailer/buildlink3.mk"
