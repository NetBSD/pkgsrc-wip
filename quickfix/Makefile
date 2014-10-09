# $NetBSD: Makefile,v 1.7 2014/10/09 14:06:30 thomasklausner Exp $

DISTNAME=		quickfix-1.13.3
CATEGORIES=		finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quickfix/}

OWNER=			alnsn@yandex.ru
HOMEPAGE=		http://www.quickfixengine.org/
COMMENT=		FIX engine
LICENSE=		quickfix

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/quickfix

USE_LANGUAGES+=	c c++
PTHREAD_OPTS+=	native
PTHREAD_AUTO_VARS=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		gmake bash

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
