# $NetBSD: Makefile,v 1.1.1.1 2007/12/09 05:33:24 hoka_adam Exp $
#

DISTNAME=		stegdetect-0.6
CATEGORIES=		security
MASTER_SITES=	http://www.outguess.org/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://www.outguess.org/
COMMENT=		Steganography detection and break tool

USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=      3.0

# Segfaults when compiled with GCC4
#
.if !empty(MACHINE_PLATFORM:MNetBSD-4*)
USE_PKGSRC_GCC= yes
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/stegbreak
	${INSTALL_DATA} ${FILESDIR}/rules.ini ${PREFIX}/share/stegbreak

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
