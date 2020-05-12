# $NetBSD: Makefile$

DISTNAME=	fltk-legacy-2.0
# Last distribution snapshot was 6129. New version should be higher.
# FLTK library itself defines version 2.1.0 in headerfile (use that).
PKGNAME=	fltk2-2.1git
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=fltk/}
GITHUB_TAG=	branch-2.0
EXTRACT_SUFX=	.zip

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
# The LGPL license is relaxed to allow static linking
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++03
USE_TOOLS+=		autoconf gmake

WRKSRC=			${WRKDIR}/fltk-legacy-branch-2.0

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	ac_cv_have_overlay=yes
LDFLAGS+=		-lfontconfig -lXrender -lfreetype

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
