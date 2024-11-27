# $NetBSD: buildlink3.mk,v 1.0 2024/05/06 16:00:00 dkazankov Exp $

BUILDLINK_TREE+=	xmlada

.if !defined(XMLADA_BUILDLINK3_MK)
XMLADA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlada+=	xmlada>=24.0.0
BUILDLINK_PKGSRCDIR.xmlada=	../../wip/xmlada
BUILDLINK_DEPMETHOD.xmlada?=	build

BUILDLINK_AUTO_VARS.xmlada=	no
BUILDLINK_AUTO_DIRS.xmlada=	no

BUILDLINK_FILES.xmlada=		lib/*
BUILDLINK_FILES.xmlada=		include/xmlada/* lib/xmlada/*
BUILDLINK_FILES.xmlada+=	share/gpr/manifests/xmlada share/gpr/xmlada*.gpr

BUILDLINK_CONTENTS_FILTER.xmlada=	\
	${EGREP} '(include/.*\.ads$$|lib/.*\.ali$$|lib/.*\.a$$|lib/libxmlada.*\.so$$|share/gpr/manifests/.*|share/gpr/.*\.gpr$$)'

.endif

BUILDLINK_TREE+=	-xmlada
