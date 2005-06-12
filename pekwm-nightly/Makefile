# $NetBSD: Makefile,v 1.4 2005/06/12 23:51:25 kristerw Exp $
#

DISTNAME=	pekwm-cvs
PKGNAME=	${DISTNAME:S/cvs/nightly-${PKGVER}/}
CATEGORIES=	wm
MASTER_SITES=	http://pekwm.org/files/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://pekwm.org/
COMMENT=	Window manager based on aewm++ (CVS version)

GNU_CONFIGURE=	    yes
USE_TOOLS+=	    gmake
USE_PERL5=	    run
USE_LANGUAGES=	    c c++
NO_CHECKSUM=	    # defined

.include "../../mk/bsd.prefs.mk"

PKGVER!=	${DATE} +%Y%m%d
DESCR_SRC=	../../wm/pekwm/DESCR

# don't forget to change this to ${PKGVER} if you have trouble
post-extract:
	@${MV} ${WRKDIR}/${DISTNAME}-20040320 ${WRKDIR}/${DISTNAME}

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

CONFIGURE_ARGS+=	--enable-imlib2
CONFIGURE_ARGS+=	--enable-harbour
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
