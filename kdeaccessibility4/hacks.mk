# $NetBSD: hacks.mk,v 1.1 2009/08/04 21:50:22 mwdavies Exp $

post-patch:
	cp ${BUILDLINK_PREFIX.kdelibs}/include/kspeech.h ${WRKSRC}/kttsd/kttsd/kspeech.h
