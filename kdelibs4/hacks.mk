# $NetBSD: hacks.mk,v 1.1 2011/05/13 23:25:15 mwdavies Exp $

.if ${OPSYS} == "NetBSD"
post-configure:
	cp ${FILESDIR}/kshareddatacache.cpp ${WRKSRC}/kdecore/util/kshareddatacache.cpp
.endif
