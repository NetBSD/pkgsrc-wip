# $NetBSD: hacks.mk,v 1.2 2012/01/22 21:04:29 mwdavies Exp $

.if ${OPSYS} == "NetBSD"
post-configure:
	cp ${FILESDIR}/kshareddatacache.cpp ${WRKSRC}/kdecore/util/kshareddatacache.cpp
.endif

# fix up buildlinks failure to build link tree correctly
post-wrapper:
	ln -s netbsd-g++ ${BUILDLINK_DIR}/qt4/mkspecs/default
