# $NetBSD: Makefile,v 1.5 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	arcem-20100819
CATEGORIES=	emulators
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.tar.bz2

INSTALLATION_DIRS=	bin \
			share/${PKGBASE}

CONFLICTS+=	arcem-[0-9]*

LINUX_FILES=	\
		linux.rom.gz \
		HardImage1.gz

.for f in ${LINUX_FILES}
SITES.${f}+=	\
		ftp://ftp.arm.uk.linux.org/pub/linux/arcem/
.endfor

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LINUX_FILES}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://arcem.sourceforge.net/
COMMENT=	Dave Gilbert's Acorn Archimedes emulator

USE_TOOLS+=	gmake

MAKE_ENV+=	SYSTEM=X

post-install:
	${INSTALL_DATA} ${WRKDIR}/linux.rom ${DESTDIR}${PREFIX}/share/${PKGBASE}/ROM
	${INSTALL_DATA} ${WRKDIR}/HardImage1 ${DESTDIR}${PREFIX}/share/${PKGBASE}/HardImage1
	${INSTALL_DATA} ${FILESDIR}/dot.arcemrc \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/dot.arcemrc
	${INSTALL_DATA} ${WRKSRC}/hexcmos ${DESTDIR}${PREFIX}/share/${PKGBASE}/hexcmos

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
