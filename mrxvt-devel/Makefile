# $NetBSD: Makefile,v 1.3 2005/03/03 19:12:28 tnn2 Exp $
#

DISTNAME=	mrxvt-0.3.13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=materm/}

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://materm.sourceforge.net/
COMMENT=	Multi-tabbed terminal emulator (development version)

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--enable-text-shadow
CONFIGURE_ARGS+=	--enable-24bits

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin"
# Make mrxvt setuid root so that tty ownership setting and utmp logging
# function correctly.
#
CONFIGURE_ARGS+=--enable-ttygid
SPECIAL_PERMS=	${PREFIX}/bin/mrxvt ${SETUID_ROOT_PERMS}
.endif

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
