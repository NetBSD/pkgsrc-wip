# $NetBSD: Makefile,v 1.3 2010/08/01 14:57:09 asau Exp $
#

DISTNAME=	nsp2-cvs_20090724
PKGNAME=	nsp2-20090724
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://cermics.enpc.fr/~jpc/nsp-tiddly/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cermics.enpc.fr/~jpc/nsp-tiddly/
COMMENT=	A scientific software package similiar to Matlab, Scilab, octave
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/nsp2
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	pkg-config automake autoconf
USE_LANGUAGES=		c c++ fortran77

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
