# $NetBSD: Makefile,v 1.5 2013/08/21 09:37:53 rhialto Exp $

PKGNAME=		flam3-2.7
DISTNAME=		flam3
CATEGORIES=		x11
MASTER_SITES=		http://electricsheep.org/
LICENSE=		gnu-gpl-v2

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://flam3.com/
COMMENT=		Cosmic Recursive Fractal Flames

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

SVN_REPOSITORIES=	flam3
SVN_REPO.flam3=		http://svn.code.sf.net/p/flam3/code/trunk
WRKSRC=			${WRKDIR}/flam3/src

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
