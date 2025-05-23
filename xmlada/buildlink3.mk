# $NetBSD: buildlink3.mk,v 1.0 2024/05/06 16:00:00 dkazankov Exp $

BUILDLINK_TREE+=	xmlada

.if !defined(XMLADA_BUILDLINK3_MK)
XMLADA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlada+=	xmlada>=24.0.0
BUILDLINK_ABI_DEPENDS.xmlada+=	xmlada>=25.0.0
BUILDLINK_PKGSRCDIR.xmlada?=	../../wip/xmlada
BUILDLINK_DEPMETHOD.xmlada?=	build

BUILDLINK_CONTENTS_FILTER.xmlada=	\
	${EGREP} '(include/.*\.ad.$$|lib/.*\.ali$$|lib/.*\.a$$|lib/.*\.so.*$$|share/gpr/manifests/.*|share/gpr/.*\.gpr$$)'

pkgbase := xmlada
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+=	-xmlada
