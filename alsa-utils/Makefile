# $NetBSD: Makefile,v 1.2 2005/04/11 21:09:41 tvierling Exp $
#

DISTNAME=		alsa-utils-1.0.4
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.alsa-project.org/pub/utils/
MASTER_SITES=		http://www.alsa-project.org/alsa/ftp/utils/	\
			ftp://ftp.alsa-project.org/pub/utils/		\
			ftp://ftp.silug.org/pub/alsa/utils/		\
			ftp://gd.tuwien.ac.at/opsys/linux/alsa/utils/	\
			ftp://linux.sarang.net/mirror/driver/sound/alsa/utils/ \
			http://gd.tuwien.ac.at/opsys/linux/alsa/utils/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.alsa-project.org/
COMMENT=		Advanced Linux Sound Architecture (ALSA) command-line utilities

GNU_CONFIGURE=		yes

.include "../../wip/alsa-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
