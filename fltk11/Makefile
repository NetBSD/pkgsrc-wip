# $NetBSD$

DISTNAME=	fltk-1.1.10-source
PKGNAME=	${DISTNAME:S/-source//:S/fltk/fltk11/}
VERS=		${DISTNAME:S/fltk-//:S/-source//}
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/fltk/${VERS}/
MASTER_SITES+=	ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/fltk/${VERS}/
EXTRACT_SUFX=	.tar.bz2

SUPERSEDES+=	fltk<1.3.0
CONFLICTS+=	fltk13-[0-9]*
CONFLICTS+=	fltk2-[0-9]*
CONFLICTS+=	fltk-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces (old 1.1 branch)
LICENSE=	gnu-lgpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
TEST_TARGET=		test

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libtool=${LIBTOOL:Q}
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	ac_cv_have_overlay=yes

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		cs	# case-sensitive
.if !exists(./descr) && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--with-links
PLIST.cs=		yes
.endif

# Fl_Text_Buffer.cxx: In function 'char chooseNullSubsChar(char*)':
# Fl_Text_Buffer.cxx:1338:34: error: array subscript has type 'char' [-Werror=char-subscripts]
#      if ( hist[ replacements[ i ] ] == 0 )
#                                   ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts


BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
