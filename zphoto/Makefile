# $NetBSD: Makefile,v 1.4 2005/06/11 11:10:32 obache Exp $
#

DISTNAME=	zphoto-1.2
CATEGORIES=	graphics
MASTER_SITES=	http://namazu.org/~satoru/zphoto/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://namazu.org/~satoru/zphoto/
COMMENT=	Flash-based photo album generator

.include "options.mk"

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
TOOLS_DEPMETHOD.perl?=	BUILD_DEPENDS

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext-lib}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../wip/ming/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
