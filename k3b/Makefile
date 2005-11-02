# $NetBSD: Makefile,v 1.6 2005/11/02 18:00:19 thomasklausner Exp $
#

DISTNAME=		k3b-0.11.24
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=k3b/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://www.k3b.org/
COMMENT=		DVD and CD authoring program

DEPENDS+=  		cdrdao-[0-9]*:../../sysutils/cdrdao
DEPENDS+=  		{cdrecord,cdrtools-ossdvd}-[0-9]*:../../sysutils/cdrecord

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake automake
USE_LIBTOOL=            yes
USE_LANGUAGES=          c c++

# XXX: does this really need automake?  autoheader is part of autoconf
AUTOMAKE_REQD=  1.7.9

pre-configure:
	cd ${WRKSRC} && autoheader
	cd ${WRKSRC} && autoconf

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

