# $NetBSD: Makefile,v 1.4 2003/06/23 12:34:17 xtraeme Exp $
#

DISTNAME=	trickle-1.06
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://monkey.org/~marius/trickle/
COMMENT=	Portable lightweight userspace bandwidth shaper

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/trickle
CONF_FILES=	${PREFIX}/share/examples/trickle/trickled.conf \
	    	${PKG_SYSCONFDIR}/trickled.conf
pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/trickled.conf ${EGDIR}

.if !exists(/usr/include/event.h)
.include "../../devel/libevent/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
