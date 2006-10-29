# $NetBSD: Makefile,v 1.2 2006/10/29 11:23:11 shattered Exp $

MODNAME=		recode
CATEGORIES+=		converters
MAINTAINER=		evaldo@gardenali.biz
COMMENT=		PHP extension for recode support

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.recode}

.include "../../lang/php/ext.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
