# $NetBSD: Makefile,v 1.2 2003/11/28 07:29:54 blef Exp $

DISTNAME=	tuxnes-0.75
CATEGORIES=	games emulators
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=tuxnes/}

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://tuxnes.sf.net/
COMMENT=	NES emulator for i386

ONLY_FOR_PLATFORM=	*-*-i[3-6]86

GNU_CONFIGURE=	YES
USE_BUILDLINK2= YES
USE_GNU_TOOLS+=	make

USE_X11=	YES
#CPPFLAGS+=	-DDSP=\"\\\"${DEVOSSAUDIO}\\\"\"

#.include "../../mk/bsd.prefs.mk"

#.if ${OPSYS} == "NetBSD"
#LDFLAGS+=	-lossaudio
#.endif

.include "../../devel/zlib/buildlink2.mk"

#.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
