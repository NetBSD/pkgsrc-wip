# $NetBSD: Makefile,v 1.4 2004/02/04 07:04:30 minskim Exp $

DISTNAME=	liteamp-0.2.4.1
CATEGORIES=	audio
MASTER_SITES=	http://download.kldp.net/liteamp/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://kldp.net/projects/liteamp/
COMMENT=	Light-weight Music Player for GNOME2

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_PERL5=		build

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	libtool

CONFIGURE_ENV+=		INTLTOOL_PERL=${PERL5}

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
