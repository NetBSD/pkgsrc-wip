# $NetBSD: Makefile,v 1.3 2012/10/05 11:12:56 asau Exp $

MODNAME=		recode
CATEGORIES+=		converters
MAINTAINER=		evaldo@gardenali.biz
COMMENT=		PHP extension for recode support

PKG_DESTDIR_SUPPORT=	none

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.recode}

.include "../../lang/php/ext.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
