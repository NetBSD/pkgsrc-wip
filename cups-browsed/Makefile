# $NetBSD$

GITHUB_PROJECT=	cups-browsed
DISTNAME=	cups-browsed-2.0.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}
GITHUB_RELEASE=	2.0.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenPrinting/cups-browsed/
COMMENT=	
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		bash:run pkg-config gmake gdbus-codegen

.include "../../net/avahi/buildlink3.mk"
.include "../../wip/libcupsfilters/buildlink3.mk"
.include "../../wip/libppd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
