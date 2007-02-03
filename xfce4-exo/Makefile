# $NetBSD: Makefile,v 1.9 2007/02/03 17:20:30 xtraeme Exp $

.include "../../wip/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.2

DISTNAME=	exo-${XFCE4_VERSION}
PKGNAME=	xfce4-exo-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce extension library

DEPENDS+=	p5-URI>=0:../../www/p5-URI

.if !empty(OPSYS:MNetBSD)
.  if exists(/usr/include/mmintrin.h)
CFLAGS+=	-msse
.  endif
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
