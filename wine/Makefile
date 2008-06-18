# $NetBSD: Makefile,v 1.13 2008/06/18 11:46:04 asau Exp $

DISTNAME=	wine-1.0
PKGNAME=	${DISTNAME:S/0-/0/}
CATEGORIES=	emulators
MASTER_SITES=	http://ibiblio.org/pub/linux/system/emulators/wine/ \
		${MASTER_SITE_SOURCEFORGE:=wine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru, adam.hoka@gmail.com
HOMEPAGE=	http://www.winehq.com/
COMMENT=	Free implementation of the Windows(tm) runtime on POSIX

BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386 Linux-*-i386 SunOS-*-i386 Darwin-*-i386
ONLY_FOR_PLATFORM+=	*-*-x86_64

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		bison flex gmake mktemp
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES=	datasize

REPLACE_PERL+=		tools/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
#
CONFIGURE_ENV+=		X_LIBS=${LDFLAGS:M*:Q}
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:Q}\ -DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
LIBS+=			${LDFLAGS}

.include "options.mk"

# Sample code how to fall back to particular GCC version:
#
# .include "../../mk/compiler.mk"
# .if !empty(CC_VERSION:Mgcc-4*)
#
# .include "../../lang/gcc34/buildlink3.mk"
#
# pre-configure:
# 	${ECHO} "GCC 4.x detected, falling back to GCC 3.4!"
# .	include "../../lang/gcc34/preconfigure.mk"
# .endif

post-install:
.for tool in fnt2bdf
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/tools/${tool} \
		${DESTDIR}${PREFIX}/bin
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
