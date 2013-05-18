# $NetBSD: Makefile,v 1.1 2013/05/18 13:22:23 othyro Exp $
#

DISTNAME=	mkcomposecache-1.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Used for creating global (system-wide) Compose cache files
#LICENSE=	# XXX SUSE license ?

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
