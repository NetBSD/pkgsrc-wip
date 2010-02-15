# $NetBSD: Makefile,v 1.5 2010/02/15 16:47:13 thomasklausner Exp $
#

DISTNAME=		gnomad2-2.8.8
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnomad2/}

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://gnomad2.sourceforge.net/
COMMENT=		GTK+2 tool for managing Creative and Dell mp3 players

DEPENDS+=	p5-XML-Parser>=2.34:../../textproc/p5-XML-Parser

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	PKG_CONFIG=${PREFIX}/bin/pkg-config

USE_TOOLS+=perl

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/libnjb/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
