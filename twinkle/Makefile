# $NetBSD: Makefile,v 1.2 2006/01/05 10:11:26 ghen Exp $
#

DISTNAME=		twinkle-0.4.2
CATEGORIES=		audio chat
MASTER_SITES=		http://www.xs4all.nl/~mfnboer/twinkle/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.twinklephone.com/
COMMENT=		Software Phone using the SIP protocol

USE_TOOLS+=	pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+="--without-kde"

.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
## x11/qt3-libs/ is broken
## cp work/qt-x11-free-3.3.5/lib/qt-mt.pc /usr/pkg/lib/pkgconfig/
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../wip/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
