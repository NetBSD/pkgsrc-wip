# $NetBSD: Makefile,v 1.1.1.1 2004/01/17 21:01:58 minskim Exp $

DISTNAME=	liteamp-0.2.4.1
CATEGORIES=	audio
MASTER_SITES=	http://download.kldp.net/liteamp/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://kldp.net/projects/liteamp/
COMMENT=	Light-weight Music Player for GNOME2

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	libtool
#post-patch:
#	${REINPLACE_CMD} -e '15s,^,#include <pthread.h>,' \
#		${WRKSRC}/src/decoder.c

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
