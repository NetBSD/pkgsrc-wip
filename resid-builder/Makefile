# $NetBSD: Makefile,v 1.4 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	resid-builder-1.0.1+20060528.ccr
PKGNAME=	resid-builder-20060528
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.tnsp.org/xs-files/
COMMENT=	reSID-builder snapshot from ccr/TNSP

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	make pkg-config pax
USE_LIBTOOL=	yes

# I know it's dirty...
#
RESID=resid-0.16.2-ccr
CONFIGURE_ARGS+= --with-resid=${WRKDIR}/${RESID}

pre-extract:
	cd ${WRKDIR} && ${FETCH_CMD} ${MASTER_SITES}/${RESID}.tar.gz
	cd ${WRKDIR} && pax -rzf ${RESID}.tar.gz

pre-configure:
	cd ${WRKDIR}/${RESID} && ./configure && make

.include "../../wip/libsidplay2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
