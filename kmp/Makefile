# $NetBSD: Makefile,v 1.1.1.1 2004/03/23 01:13:06 rockpiper Exp $

DISTNAME=	kmp-0.01
CATEGORIES=	audio
MASTER_SITES=	http://www.threadbox.net/files/KMP/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkg@burningsoda.com
HOMEPAGE=	http://www.threadbox.net/kmp.php
COMMENT=	KMP is a Qt Client for the fantastic Music Player Daemon.

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	NO
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT= configure
CONFIGURE_ARGS+= ${LOCALBASE}

.include "../../mk/bsd.prefs.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
