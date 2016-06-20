# $NetBSD: Makefile,v 1.9 2013/12/19 06:03:37 othyro Exp $
#

DISTNAME=	dssi-1.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dssi/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://dssi.sourceforge.net/
COMMENT=	API for audio processing plugins
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake gsed pkg-config
USE_LANGUAGES=	c c++ fortran

PKGCONFIG_OVERRIDE+=	dssi.pc.in

.include "options.mk"

.if $(OPSYS) != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
.endif


.include "../../mk/dlopen.buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
BUILDLINK_DEPMETHOD.libdssialsacompat=	full
.include "../../wip/libdssialsacompat/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
