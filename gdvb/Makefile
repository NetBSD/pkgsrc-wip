# $NetBSD: Makefile,v 1.4 2010/06/13 22:47:04 thomasklausner Exp $
#

DISTNAME=	gdvb-0.2
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.nopcode.org/prj/gdvb/ \
		http://cvs.nopcode.org/ftp/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=gdvb
COMMENT=	DVB channels manager frontend using JavaGTK

DEPENDS+=	mplayer-[0-9]*:../../multimedia/mplayer
DEPENDS+=	linuxtv-dvb-apps>=1.0:../../wip/linuxtv-dvb-apps

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../wip/libgtk-java/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
