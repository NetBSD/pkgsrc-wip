# $NetBSD: Makefile,v 1.1 2014/10/10 20:40:16 nros Exp $

DISTNAME=	gimp-dds-3.0.1
CATEGORIES=	graphics
MASTER_SITES=	https://gimp-dds.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/gimp-dds/
COMMENT=	DDS io gimp plugin
LICENSE=	gnu-gpl-v2 AND mit

USE_TOOLS+=	gmake pkg-config

GCC_REQD=	4.9

gimplibdir=	pkg-config --variable=gimplibdir gimp-2.0

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${gimplibdir:sh}/plug-ins
	${INSTALL_LIB} ${WRKSRC}/dds \
		${DESTDIR}${gimplibdir:sh}/plug-ins

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
