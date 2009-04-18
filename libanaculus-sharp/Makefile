# $NetBSD: Makefile,v 1.1.1.1 2009/04/18 00:24:20 jihbed Exp $
#

DISTNAME=	libanculus-sharp-0.3.1
CATEGORIES=	devel
MASTER_SITES=	http://libanculus-sharp.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/libanculus-sharp/
COMMENT=	Libanculus-sharp is a reusable utility library written in C#

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config automake autoconf gmake
USE_LANGUAGES=	c c++


pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh --prefix=${DESTDIR}${PREFIX}

CONFIGURE_ARGS+=        --disable-monodoc
CONFIGURE_ARGS+=        --disable-winforms

PKGCONFIG_OVERRIDE+=	src/Anculus.Core/anculus-core.pc.in
PKGCONFIG_OVERRIDE+=	src/Anculus.Core.Extended/anculus-core-extended.pc.in
PKGCONFIG_OVERRIDE+=	src/Anculus.Gui/anculus-gui.pc.in

.include "options.mk"

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
