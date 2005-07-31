# $NetBSD: Makefile,v 1.5 2005/07/31 19:36:16 shattered Exp $
#

DISTNAME=		d4x-2.5.0final
PKGNAME=		d4x-2.5.0
CATEGORIES=		net
MASTER_SITES=		http://www.krasu.ru/soft/chuchelo/files/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.krasu.ru/soft/chuchelo/files/
COMMENT=		Download files using a nice GUI

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
LIBCOMPAT=	-lcompat
.else
LIBCOMPAT=	# none?
.endif

MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO} LIBCOMPAT=${LIBCOMPAT}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
