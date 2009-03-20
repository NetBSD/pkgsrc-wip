# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libpcap

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.3
BUILDLINK_PKGSRCDIR.libpcap?=	../../wip/libpcap-latest

.include "../../mk/bsd.prefs.mk"

# on Solaris, we always need libnsl and libsocket because libpcap.a
# references symbols in them.
.if ${OPSYS} == "SunOS"
BUILDLINK_LDADD.libpcap+=	-lnsl -lsocket
LDFLAGS+=			${BUILDLINK_LDADD.libpcap}
.endif
.endif # LIBPCAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpcap
