# $NetBSD: Makefile,v 1.2 2004/04/25 18:08:36 blef Exp $

DISTNAME=	kmp-0.01
CATEGORIES=	audio
MASTER_SITES=	http://www.threadbox.net/files/KMP/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkg@burningsoda.com
HOMEPAGE=	http://www.threadbox.net/kmp.php
COMMENT=	KMP is a Qt Client for the fantastic Music Player Daemon.

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	NO
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT= configure
CONFIGURE_ARGS+= ${LOCALBASE}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
