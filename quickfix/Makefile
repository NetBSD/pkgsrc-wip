# $NetBSD: Makefile,v 1.7 2014/10/09 14:06:30 thomasklausner Exp $

DISTNAME=	quickfix-1.14.4
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=quickfix/}
GITHUB_TAG=	v.${PKGVERSION}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION}//}

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	http://www.quickfixengine.org/
COMMENT=	FIX engine
LICENSE=	quickfix

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/quickfix-${GITHUB_TAG}

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake autoconf automake m4
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CHECK_PORTABILITY_SKIP=	configure # XXX Don't play with fire!
PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/mysql55-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
