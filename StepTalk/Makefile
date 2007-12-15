# $NetBSD: Makefile,v 1.1.1.1 2007/12/15 04:03:44 dvol Exp $
#

DISTNAME=	StepTalk-0.10.0
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
