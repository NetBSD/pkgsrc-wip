# $NetBSD: Makefile,v 1.1.1.1 2004/01/05 17:26:51 poppnk Exp $
#

DISTNAME=		icecast-2.0-beta-3
CATEGORIES=		audio wip
MASTER_SITES=		http://www.icecast.org/files/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.icecast.org/
COMMENT=		Live streaming audio server

# XXX seems that CONFLICTS doesn't works :/
CONFLICTS+=		icecast>=1.3:../../audio/icecast/
CONFLICTS+=		icecast>=1.3:../../wip/icecast/
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if defined(ICECAST2_USE_CURL) && ${ICECAST2_USE_CURL} == "YES"
.include "../../www/curl/buildlink2.mk"
.endif

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
