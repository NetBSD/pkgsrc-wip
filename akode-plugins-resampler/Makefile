# $NetBSD: Makefile,v 1.1.1.1 2009/02/23 08:42:51 htepper Exp $
#

PKGNAME=		akode-plugins-resampler-${AKODE_VERSION}

MAINTAINER=		hasso@NetBSD.org
COMMENT=		Resampler plugin for aKode framework

.include "../../wip/akode/Makefile.common"

DISTINFO_FILE=          ${.CURDIR}/../../wip/akode/distinfo
PATCHDIR=               ${.CURDIR}/../../wip/akode/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-libsamplerate

do-install:
	cd ${WRKSRC}/akode/plugins/src_resampler && ${SETENV} ${MAKE_ENV} \
		${MAKE} prefix=${DESTDIR}${PREFIX} install

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../wip/akode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
