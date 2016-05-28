# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:29 asau Exp $
#

DISTNAME=	StepTalk-0.10.0
PKGREVISION=	1
CATEGORIES=	gnustep devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=libs/}

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://www.gnustep.org/experience/StepTalk.html
COMMENT=	GNUstep scripting framework


WRKSRC=		${WRKDIR}/StepTalk
USE_LANGUAGES=	objc
NO_CONFIGURE=	yes

.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
