# $NetBSD: Makefile,v 1.2 2010/12/26 05:01:22 davesainty Exp $

PKGNAME=		flam3-2.7
DISTNAME=		flam3
CATEGORIES=		x11
MASTER_SITES=		http://electricsheep.org/

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://flam3.com/
COMMENT=		Cosmic Recursive Fractal Flames

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

SVN_REPOSITORIES=	flam3
SVN_ROOT.flam3=		http://electricsheep.svn.sourceforge.net/svnroot/flam3/trunk
WRKSRC=			${WRKDIR}/flam3/src

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
