# $NetBSD: Makefile,v 1.1.1.1 2005/02/08 17:03:53 daprice Exp $
#

DISTNAME=		grass-5.0.3_src
PKGNAME=		grass-5.0.3
CATEGORIES=		geography
MASTER_SITES=		http://grass.itc.it/grass50/source/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://grass.itc.it/index.html
COMMENT=		Open source, free software geographical information system (GIS)

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-postgres-includes=${PREFIX}/include/postgresql
CONFIGURE_ARGS+=	--with-fftw=no
CONFIGURE_ARGS+=	--with-fftw=no
CONFIGURE_ARGS+=	--with-gdal=yes

WRKSRC=			${WRKDIR}/grass-5.0.3

LDFLAGS+=		-lpthread

post-install:
	${TOUCH} ${PREFIX}/grass5/txt/MONITOR/.keepme
	${TOUCH} ${PREFIX}/grass5/txt/DIGIT2/.keepme
	${TOUCH} ${PREFIX}/grass5/man/man5/.keepme
	${TOUCH} ${PREFIX}/grass5/man/man4/.keepme
	${TOUCH} ${PREFIX}/grass5/man/man3/.keepme
	${TOUCH} ${PREFIX}/grass5/man/man2/.keepme
	${TOUCH} ${PREFIX}/grass5/man/man2/.keepme
	${TOUCH} ${PREFIX}/grass5/man/help/.keepme
	${TOUCH} ${PREFIX}/grass5/locale/.keepme
	${TOUCH} ${PREFIX}/grass5/etc/sites/.keepme
	${TOUCH} ${PREFIX}/grass5/etc/dig_drivers/.keepme

.include "../../wip/gdal/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
