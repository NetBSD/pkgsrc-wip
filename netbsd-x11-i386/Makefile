# $NetBSD: Makefile,v 1.1 2015/05/03 15:01:12 spz Exp $

DISTNAME=		netbsd-x11-i386-7.0
HOMEPAGE=		http://www.NetBSD.org/releases/formal-7/index.html
COMMENT=		Shared X11 libraries for NetBSD 7.0/i386
CATEGORIES=		emulators
LICENSE=		mit

MASTER_SITES=		http://mirror.isoc.org.il/pub/netbsd/NetBSD-7.0/i386/binary/sets/
EMUL_PLATFORMS=		netbsd-i386

DISTFILES=		xbase.tgz xcomp.tgz xetc.tgz xfont.tgz xserver.tgz

WRKSRC=			${WRKDIR}/usr/X11R7

# XXX crimes
NO_BUILD=		yes

do-install:                                                
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}
	cd ${WRKSRC} && for dir in lib libexec usr; do		\
	if ${TEST} -d "$$dir"; then				\
	pax -rw "$$dir"						\
	${DESTDIR}${PREFIX};					\
	fi;							\
	done

		 	

.include "../../mk/bsd.pkg.mk"
