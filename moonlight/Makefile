# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:28 thomasklausner Exp $

DISTNAME=	moon-1.0.1
PKGREVISION=	1
CATEGORIES=	multimedia
PKGNAME=	moonlight-1.0.1
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/moon/1.0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
COMMENT=	Open Source implementation of Microsoft Silverlight for UNIX Systems
HOMEPAGE=	http://mono-project.com/Moonlight

PKG_DESTDIR_SUPPORT=    user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=			--with-cairo=system
# XXX: TODO
#CONFIGURE_ARGS=		--with-managed=yes

USE_LANGUAGES=	c c++
USE_TOOLS=	bash gmake pkg-config
USE_LIBTOOL=	yes

BUILDLINK_TRANSFORM+=\
  opt:-lxpcomglue_s:${PREFIX}/lib/xulrunner/libxpcomglue_s.a

ONLY_FOR_PLATFORM=	Linux-*-i386 Linux-*-x86_64 NetBSD-*-i386 NetBSD-*-x86_64

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/xulrunner/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
