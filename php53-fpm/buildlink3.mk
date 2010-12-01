# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/12/01 15:47:49 anielski Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=5.3.2
BUILDLINK_ABI_DEPENDS.php+=	php>=5.3.2
BUILDLINK_PKGSRCDIR.php?=	../../lang/php53

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
