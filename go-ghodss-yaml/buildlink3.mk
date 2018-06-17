# $NetBSD$

BUILDLINK_TREE+=	go-ghodss-yaml

.if !defined(GO_GHODSS_YAML_BUILDLINK3_MK)
GO_GHODSS_YAML_BUILDLINK3_MK=

BUILDLINK_CONTENTS_FILTER.go-ghodss-yaml=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ghodss-yaml?=		build

BUILDLINK_API_DEPENDS.go-ghodss-yaml+=		go-ghodss-yaml>=0.0
BUILDLINK_PKGSRCDIR.go-ghodss-yaml?=		../../wip/go-ghodss-yaml

.include "../../devel/go-yaml/buildlink3.mk"
.endif  # GO_GHODSS_YAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ghodss-yaml
