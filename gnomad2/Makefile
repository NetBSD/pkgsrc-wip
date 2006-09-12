# $NetBSD: Makefile,v 1.1.1.1 2006/09/12 12:14:56 neimal Exp $
#

DISTNAME=		gnomad2-2.8.8
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnomad2/}

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://belnet.dl.sourceforge.net/sourceforge/gnomad2/
COMMENT=		GTK+2 tool for managing Creative and Dell mp3 players

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

#CFLAGS+=		-I${PREFIX}/include
#CPPFLAGS+=		-I${PREFIX}/include
#PKGC=			${PREFIX}/bin/pkg-config
CONFIGURE_ARGS+=	PKG_CONFIG=${PREFIX}/bin/pkg-config

USE_TOOLS+=perl

DEPENDS+=       p5-XML-Parser>=2.34:../../textproc/p5-XML-Parser

.include "../../wip/libmtp/buildlink3.mk"
.include "../../wip/libnjb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
