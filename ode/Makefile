# $NetBSD: Makefile,v 1.6 2010/07/04 16:38:10 hftmarkand Exp $

DISTNAME=	ode-${ODE_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.zip
ODE_VERSION=	0.11.1

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	kh.p@no-log.org
HOMEPAGE=	http://www.ode.org/
COMMENT=	Library for the simulation of Rigid Body Dynamics

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE=	ode.pc.in

INSTALLATION_DIRS=	include/ode lib

CONFIGURE_ARGS+=	--enable-shared \
			--disable-double-precision

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
CFLAGS+= -fPIC
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
