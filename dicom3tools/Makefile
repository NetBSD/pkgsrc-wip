# $NetBSD: Makefile,v 1.1.1.1 2004/01/04 11:11:50 mpasternak Exp $
#

DISTNAME=		dicom3tools_1.00.snapshot.20030501.helgray
PKGNAME=		dicom3tools-20030501
CATEGORIES=		graphics
MASTER_SITES=		http://www.dclunie.com/dicom3tools/workinprogress/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.dclunie.com/
COMMENT=		Library for dealing with DICOM 3 files

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_IMAKE=		yes

do-configure:
	cd ${WRKSRC} && ${SETENV} PKGSRC_X11BASE=${X11BASE} \
		PKGSRC_PREFIX=${PREFIX} ${CONFIGURE_ENV} ./Configure
	cd ${WRKSRC} && ${IMAKE} -I./config

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} World

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install install.man

.if exists(../../mk/opengl.buildlink2.mk)
# see PR #23845 for details
.include "../../mk/opengl.buildlink2.mk"
.else
.include "../../graphics/Mesa/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
