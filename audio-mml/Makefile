# $NetBSD: Makefile,v 1.5 2012/10/23 10:23:06 thomasklausner Exp $
#

DISTNAME=	rat-4.4.01r4121
PKGNAME=	audio-mml-4.4.01
CATEGORIES=	mbone audio multimedia
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/
COMMENT=	Real-time Audio Tool

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	tclsh wish # XXX verify

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=	EGDIR=${EGDIR}

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-tcltk=${WISH}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-common=${BUILDLINK_PREFIX.common-mml}
BUILDLINK_TRANSFORM+=	l:tcl80:tcl
BUILDLINK_TRANSFORM+=	l:tk80:tk

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/audio-mml
	${INSTALL_DATA} ${WRKSRC}/*.h ${DESTDIR}${PREFIX}/include/audio-mml

.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../wip/common-mml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
