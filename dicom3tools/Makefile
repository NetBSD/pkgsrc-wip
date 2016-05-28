# $NetBSD: Makefile,v 1.8 2012/09/28 21:24:36 asau Exp $
#

DISTNAME=		dicom3tools_1.00.snapshot.20061010
PKGNAME=		dicom3tools-20061010
EXTRACT_SUFX=		.tar.bz2

CATEGORIES=		graphics
MASTER_SITES=		http://www.dclunie.com/dicom3tools/workinprogress/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.dclunie.com/
COMMENT=		Library for dealing with DICOM 3 files


USE_IMAKE=		yes

do-configure:
	cd ${WRKSRC} && ${SETENV} PKGSRC_X11BASE=${X11BASE} \
		PKGSRC_PREFIX=${PREFIX} ${CONFIGURE_ENV} ./Configure
	cd ${WRKSRC} && ${IMAKE} -I./config

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} World

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install install.man

.if exists(../../mk/opengl.buildlink3.mk)
# see PR #23845 for details
.include "../../mk/opengl.buildlink3.mk"
.else
.include "../../graphics/Mesa/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
