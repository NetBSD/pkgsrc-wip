# $NetBSD: Makefile,v 1.5 2006/07/14 10:52:26 thomasklausner Exp $

.include "../../wip/xfce4/Makefile.common"

PKGNAME=	xfce4-print-${XFCE4_VERSION}
DISTNAME=	xfprint-${XFCE4_VERSION}
CATEGORIES=	print
COMMENT=	Xfce print dialog

CONFIGURE_ARGS+=	--with-printcap=/etc/printcap

.include "options.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	SOLARIS="@comment "
.else
PLIST_SUBST+=	SOLARIS=""
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/a2ps/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
