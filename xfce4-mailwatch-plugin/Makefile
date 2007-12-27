# $NetBSD: Makefile,v 1.1.1.1 2007/12/27 17:43:01 hoka_adam Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=  1.0.1

DISTNAME=	xfce4-mailwatch-plugin-${XFCE4_VERSION}
CATEGORIES=	mail
MASTER_SITES=	http://spuriousinterrupt.org/files/mailwatch/
EXTRACT_SUFX=	.tar.bz2

#I'm not sure how to test it. -hoka
#PKG_DESTDIR_SUPPORT=user-destdir

CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include \
			--x-libraries=${X11BASE}/libs

HOMEPAGE=	http://spuriousinterrupt.org/projects/mailwatch/
COMMENT=	Xfce mail checker plugin for the panel

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
