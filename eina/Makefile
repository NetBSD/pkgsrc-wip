# $NetBSD: Makefile,v 1.4 2008/10/29 22:53:22 yazzy Exp $
#

DISTNAME=       eina-0.9.0.050
PKGREVISION=    1
CATEGORIES=     devel
MASTER_SITES=   http://www.ezunix.org/pkgsrc/e17/snapshots/2008-09-25/

EXTRACT_SUFX=   .tar.bz2
MAINTAINER=     yazzy@yazzy.org
HOMEPAGE=       http://enlightenment.org/
COMMENT=        Data types library

GNU_CONFIGURE=  yes
USE_LIBTOOL=    yes
USE_TOOLS=      gmake pkg-config automake autoconf autoheader aclocal

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../wip/ecore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
