# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:24 othyro Exp $
#

DISTNAME=		jpgtn-2.06
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jpgtn/}
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://jpgtn.sourceforge.net/
COMMENT=		Thumbnail generator for JPEG images


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
