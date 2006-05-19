# $NetBSD: Makefile,v 1.8 2006/05/19 16:51:15 ykomatsu Exp $
#

DISTNAME=		d4x-2.5.0final
PKGNAME=		d4x-2.5.0
CATEGORIES=		net
MASTER_SITES=		http://www.krasu.ru/soft/chuchelo/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
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

MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q} LIBCOMPAT=${LIBCOMPAT:Q}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
