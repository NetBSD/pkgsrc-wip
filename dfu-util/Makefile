# $NetBSD: Makefile,v 1.9 2014/02/11 21:04:07 noud4 Exp $
#

DISTNAME=		dfu-util-${SVN_TAG.dfu-util}
CATEGORIES=		comms
MASTER_SITES=		#

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		http://wiki.openmoko.org/wiki/Dfu-util
COMMENT=		Host side of the USB DFU protocol
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=	dfu-util
GIT_REPO.dfu-util=	git://git.code.sf.net/p/dfu-util/dfu-util

SUBDIR=			dfu-util
WRKSRC=			${WRKDIR}/${SUBDIR}
USE_TOOLS+=		autoconf automake tar
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	-prefix=${PREFIX}
CFLAGS+=		-lusb

pre-configure:
	${CHMOD} u+x ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

.include "../../wip/mk/git-package.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
