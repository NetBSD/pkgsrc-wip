# $NetBSD: Makefile,v 1.1.1.1 2005/04/17 00:35:28 gschwarz Exp $

DISTNAME=	linphone-1.0.1
CATEGORIES=	net
MASTER_SITES=	http://simon.morlat.free.fr/download/1.0.x/source/

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://www.linphone.org
COMMENT=	a SIP-based IP telephony client

BUILD_DEFS+=	USE_INET6

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=

CONFIGURE_ARGS+=	--with-osip=${BUILDLINK_PREFIX.libosip2}
CONFIGURE_ARGS+=        --with-speex=${BUILDLINK_PREFIX.speex}
CONFIGURE_ARGS+=	--disable-manual

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=	--enable-ipv6
.endif
#.if ${MACHINE_ARCH} == "i386"
#CONFIGURE_ARGS+=	--enable-truespeech
#.endif

USE_PERL5=
DEPENDS+=	p5-XML-Parser-*:../../textproc/p5-XML-Parser

.include "../../devel/libosip/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
