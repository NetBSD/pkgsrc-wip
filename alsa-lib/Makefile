# $NetBSD: Makefile,v 1.7 2008/02/06 16:26:49 jeremy-c-reed Exp $
#

DISTNAME=		alsa-lib-1.0.16
CATEGORIES=		audio
MASTER_SITES=		http://www.alsa-project.org/alsa/ftp/lib/	\
			ftp://ftp.alsa-project.org/pub/lib/		\
			ftp://ftp.silug.org/pub/alsa/lib/		\
			ftp://gd.tuwien.ac.at/opsys/linux/alsa/lib/	\
			ftp://linux.sarang.net/mirror/driver/sound/alsa/lib/ \
			http://gd.tuwien.ac.at/opsys/linux/alsa/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.alsa-project.org/
COMMENT=		Libraries for the Advanced Linux Sound Architecture (ALSA)

ONLY_FOR_PLATFORM=	Linux-*-*

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	utils/alsa.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
