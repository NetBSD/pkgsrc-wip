# $NetBSD: Makefile,v 1.2 2008/02/03 13:56:32 hoka_adam Exp $
#

DISTNAME=		stegdetect-0.6
CATEGORIES=		security
MASTER_SITES=	http://www.outguess.org/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://www.outguess.org/
COMMENT=		Steganography detection and break tool

USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}/man

.include "../../mk/bsd.prefs.mk"

# Segfaults when compiled with GCC4
#
.if !empty(MACHINE_PLATFORM:MNetBSD-4*)
USE_PKGSRC_GCC= yes
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/stegbreak
	${INSTALL_DATA} ${FILESDIR}/rules.ini ${PREFIX}/share/stegbreak

# X11 support is pretty useless and needs gtk1.
#
#.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
