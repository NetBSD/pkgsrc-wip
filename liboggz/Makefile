# $NetBSD: Makefile,v 1.1 2013/03/02 15:31:33 othyro Exp $
#

DISTNAME=	liboggz-1.1.1
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/liboggz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xiph.org/oggz/
COMMENT=	Inspects, edits, and validates Ogg files
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	oggz.pc.in

.include "options.mk"

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
