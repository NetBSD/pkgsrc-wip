# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:03 thomasklausner Exp $
#

DISTNAME=		epplets-0.7
PKGREVISION=		2
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		Peter.Bex@student.kun.nl
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Epplets for Enlightenment

# We really don't (shouldn't?) care about version
#
# patch-ac (change ${PREFIX}/bin/dox to ${PREFIX}/bin/edox) should be changed
# to allow this, as enlightenment < 0.16.7 install ${PREFIX}/bin/dox, while
# enlightenment >= 0.16.7 installs ${PREFIX/bin/edox
#
#DEPENDS+=		enlightenment:../../wm/enlightenment
#DEPENDS+=		enlightenment>=0.16.4:../../wm/enlightenment
DEPENDS+=		enlightenment>=0.16.7:../../wm/enlightenment

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/include
# If enlightenment < 0.16.4
#CONFIGURE_ARGS+=	--disable-new-remember

.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
