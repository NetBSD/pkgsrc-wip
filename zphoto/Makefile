# $NetBSD: Makefile,v 1.2 2005/03/31 03:02:24 obache Exp $
#

DISTNAME=	zphoto-1.2
CATEGORIES=	graphics
MASTER_SITES=	http://namazu.org/~satoru/zphoto/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://namazu.org/~satoru/zphoto/
COMMENT=	Flash-based photo album generator

USE_X11=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build

.include "options.mk"

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext-lib}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../wip/ming/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
