# $NetBSD$

BUILDLINK_TREE+=	passenger

.if !defined(PASSENGER_BUILDLINK3_MK)
PASSENGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.passenger+=	${RUBY_PKGPREFIX}-passenger>=5.1
BUILDLINK_PKGSRCDIR.passenger?=		../../wip/ruby-passenger

BUILDLINK_INCDIRS.passenger+=		share/passenger/include
BUILDLINK_INCDIRS.passenger+=		share/passenger/ngx_http_passenger_module

.include "../../lang/ruby/rubyversion.mk"
.endif # PASSENGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-passenger
