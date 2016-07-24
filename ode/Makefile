# $NetBSD: Makefile,v 1.8 2013/01/19 12:25:38 othyro Exp $

DISTNAME=	ode-0.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ode.org/
COMMENT=	Library for the simulation of Rigid Body Dynamics
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE=	ode.pc.in

INSTALLATION_DIRS=	include/ode lib

CONFIGURE_ARGS+=	--enable-shared \
			--disable-double-precision # XXX Why?

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
CFLAGS+= -fPIC
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
