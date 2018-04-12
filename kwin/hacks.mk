# $NetBSD$
#
.include "../../mk/bsd.fast.prefs.mk"

pre-configure:
	ln -s libKF5GlobalAccelPrivate.so.5 ${BUILDLINK_DIR}/lib/libKF5GlobalAccelPrivate.so
.if ${OPSYS} == "NetBSD"
	mkdir ${BUILDLINK_DIR}/include/linux
	cp ${FILESDIR}/input.h ${BUILDLINK_DIR}/include/linux/input.h
.endif
