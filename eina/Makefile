# $NetBSD: Makefile,v 1.8 2008/11/19 01:14:03 jsonn Exp $
#

DISTNAME=       eina-0.0.1
CATEGORIES=     devel
MASTER_SITES=   http://www.ezunix.org/pkgsrc/e17/snapshots/2008-09-25/

EXTRACT_SUFX=   .tar.bz2
MAINTAINER=     yazzy@yazzy.org
HOMEPAGE=       http://enlightenment.org/
COMMENT=        Data types library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=  yes
USE_LIBTOOL=    yes
USE_TOOLS=      gmake pkg-config automake autoconf autoheader aclocal

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../wip/ecore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
