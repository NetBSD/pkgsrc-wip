# $NetBSD: Makefile,v 1.1.1.1 2006/11/09 10:33:34 kh-p Exp $

DISTNAME=	ode-src-0.7
PKGNAME=	ode-0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opende/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kh.p@no-log.org
HOMEPAGE=	http://www.ode.org/
COMMENT=	Library for the simulation of Rigid Body Dynamics

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	include/ode lib

CONFIGURE_ARGS+=	--enable-double-precision

## TODO: Install needs to be corrected. I'm working on it. Please do not edit.
#do-install:
#	${INSTALL_DATA} ${WRKSRC}/include/ode/*.h ${PREFIX}/include/ode
#	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/lib/libode.la \
#	${PREFIX}/lib

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
