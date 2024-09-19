# $NetBSD: Makefile,v 1.2 2012/10/05 13:52:02 asau Exp $
#

DISTNAME=	polylib-5.22.5
CATEGORIES=	math
MASTER_SITES=	http://icps.u-strasbg.fr/polylib/polylib_src/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://icps.u-strasbg.fr/polylib/polylib_src/
COMMENT=	The polyhedral library - long int version
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libgmp

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
