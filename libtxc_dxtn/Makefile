# $NetBSD: Makefile,v 1.1 2015/08/10 22:27:47 yhardy Exp $
#

DISTNAME=	libtxc_dxtn-1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://people.freedesktop.org/~cbrill/libtxc_dxtn/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.freedesktop.org/~cbrill/libtxc_dxtn/
COMMENT=	S3 texture compression support for MesaLib
LICENSE=	mit

RESTRICTED=		Need a valid license for s3tc
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INSTALL_TEMPLATES=	${FILESDIR}/INSTALL
DEINSTALL_TEMPLATES=	${FILESDIR}/DEINSTALL

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
