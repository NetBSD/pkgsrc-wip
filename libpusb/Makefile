# $NetBSD: Makefile,v 1.1.1.1 2004/11/22 16:54:30 imilh Exp $
#

DISTNAME=		libpusb
PKGNAME=		libpusb-0.1
CATEGORIES=		devel
MASTER_SITES=		http://benoit.is-a-geek.net/bsd-tmp/

MAINTAINER=		imil@gcu.info
COMMENT=		Simple and portable USB development interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=      FreeBSD-*-* NetBSD-*-* OpenBSD-*-* Linux-*-*

WRKSRC=			${WRKDIR}/libpusb/src
USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	lib

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
ALL_TARGET=		# defined
USE_LIBTOOL=		yes

pre-build:
			@cd ${WRKSRC} && ${RM} *.o # author's note..

do-install:
			${LIBTOOL} --mode=install ${INSTALL_LIB} 	\
				${WRKSRC}/libpusb.so ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
