# $NetBSD: Makefile,v 1.2 2004/05/15 13:23:57 mpasternak Exp $
#

DISTNAME=		skippy-0.4.0
CATEGORIES=		wm
MASTER_SITES=		http://thegraveyard.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://thegraveyard.org/skippy.php
COMMENT=		Fullscreen task switcher for X11

USE_BUILDLINK3=		yes
USE_X11=		# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skippy ${PREFIX}/bin/skippy

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
