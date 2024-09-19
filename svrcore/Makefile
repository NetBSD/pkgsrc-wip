# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:18 asau Exp $
#

DISTNAME=	svrcore-4.0.4
CATEGORIES=	security
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/directory/svrcore/releases/4.0.4/src/
#MASTER_SITES=	${MASTER_SITE_MOZILLA:=directory/svrcore/releases/4.0.4/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://ftp.mozilla.org/pub/mozilla.org/directory/svrcore/releases/4.0.4/src/
COMMENT=	Netscape svrcore is a kind of library to handle NSS PIN requests
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	svrcore.pc.in

.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
