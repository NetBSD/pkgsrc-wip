# $NetBSD: Makefile,v 1.1.1.1 2004/05/10 05:33:02 mpasternak Exp $
#

DISTNAME=		pearpc-0.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pearpc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://pearpc.sourceforge.net/
COMMENT=		PowerPC emulator

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-i386 # this is expected to be portable,
# but currently it will compile only on Linux/386, because this is in
# very early stage of development.

.include "../../mk/bsd.pkg.mk"
