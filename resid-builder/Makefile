# $NetBSD: Makefile,v 1.5 2012/11/13 22:25:45 othyro Exp $
#

DISTNAME=	resid-builder-1.0.1+20060528.ccr
PKGNAME=	resid-builder-20060528
CATEGORIES=	audio
MASTER_SITES=	https://www.tnsp.org/xs-files/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	https://www.tnsp.org/xs-files/
COMMENT=	Snapshot of reSID-builder from ccr/TNSP


GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	make pkg-config pax
USE_LIBTOOL=	yes

# I know it's dirty...
#
RESID=	resid-0.16.2-ccr
CONFIGURE_ARGS+= --with-resid=${WRKDIR}/${RESID}

pre-extract:
	cd ${WRKDIR} && ${FETCH_CMD} ${MASTER_SITES}/${RESID}.tar.gz
	cd ${WRKDIR} && pax -rzf ${RESID}.tar.gz

pre-configure:
	cd ${WRKDIR}/${RESID} && ./configure && make

.include "../../audio/libsidplay2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
