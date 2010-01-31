# $NetBSD: Makefile,v 1.1.1.1 2010/01/31 17:25:56 rhialto Exp $

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

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
