# $NetBSD: Makefile,v 1.4 2009/10/01 16:18:59 roelants Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.0.1

DISTNAME=	xfce4-mailwatch-plugin-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://spuriousinterrupt.org/files/mailwatch/
EXTRACT_SUFX=	.tar.bz2

#I'm not sure how to test it. -hoka
#PKG_DESTDIR_SUPPORT=user-destdir

CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include \
			--x-libraries=${X11BASE}/libs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spuriousinterrupt.org/projects/mailwatch/
COMMENT=	Xfce mail checker plugin for the panel

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
