# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:35:37 jihbed Exp $
#

DISTNAME=	polylib-5.22.5
CATEGORIES=	math
MASTER_SITES=	http://icps.u-strasbg.fr/polylib/polylib_src/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://icps.u-strasbg.fr/polylib/polylib_src/
COMMENT=	The polyhedral library - long int version
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libgmp

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
