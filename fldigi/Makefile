# $NetBSD: Makefile,v 1.1 2012/08/07 14:05:13 makoto Exp $

DISTNAME=	fldigi-3.21.49
CATEGORIES=	ham
MASTER_SITES=	https://api.opensuse.org/public/source/hamradio/fldigi
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lists.berlios.de/mailman/listinfo/fldigi-devel
COMMENT=	Digital radio modem

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
# To find _oss_ioctl
LDFLAGS+=	-lossaudio

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-configure
SUBST_FILES.perl=	scripts/fldigi-shell
SUBST_MESSAGE.perl=	Replacing Perl PATH
SUBST_SED.perl+=	-e s\|/usr/bin/perl\|${PERL5:Q}\|g

# Following binary contains configure parameter, which is OK.
CHECK_WRKREF_SKIP+=	bin/flarq
CHECK_WRKREF_SKIP+=	bin/fldigi

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../textproc/xmlrpc-c/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
