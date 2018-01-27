# $NetBSD: Makefile,v 1.6 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	ogre_src_v1-7-1
PKGNAME=	ogre-1.7.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ogre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ogre.sourceforge.net/
COMMENT=	Object-Oriented Graphics Rendering Engine

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_CMAKE=	YES
USE_TOOLS+=	gmake pkg-config xmkmf
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	CMake/Templates/OGRE-PCZ.pc.in
PKGCONFIG_OVERRIDE+=	CMake/Templates/OGREStatic.pc.in
PKGCONFIG_OVERRIDE+=	CMake/Templates/OGRE-Paging.pc.in
PKGCONFIG_OVERRIDE+=	CMake/Templates/OGRE-Terrain.pc.in
PKGCONFIG_OVERRIDE+=	CMake/Templates/OGRE-RTShaderSystem.pc.in
PKGCONFIG_OVERRIDE+=	CMake/Templates/OGRE-Property.pc.in
PKGCONFIG_OVERRIDE+=	CMake/Templates/OGRE.pc.in

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
