# $NetBSD$
#
.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
pre-configure:
	mkdir ${BUILDLINK_DIR}/include/linux
	cp ${FILESDIR}/input.h ${BUILDLINK_DIR}/include/linux/input.h
.endif
