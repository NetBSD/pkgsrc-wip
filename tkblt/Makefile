# $NetBSD: Makefile,v 1.38 2022/06/06 04:27:14 dholland Exp $

DISTNAME=	tkblt-3.2.23
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wjoye/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	https://blt.sourceforge.net/
COMMENT=	Extension to Tcl/Tk

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c99 c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ENV+=		LDF=${LDFLAGS:Q}
CFLAGS+=		-DUSE_INTERP_RESULT
MAKE_ENV+=		CP=${CP:Q}

#MAKE_JOBS_SAFE=	no

CHECK_INTERPRETER_SKIP+=	lib/*/demos/*.tcl

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
