# $NetBSD: Makefile,v 1.7 2004/04/25 18:28:07 blef Exp $
# FreeBSD Id: ports/devel/cvsd/Makefile,v 1.18 2003/04/26 22:38:53 nork Exp

DISTNAME=	cvsd-1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://tiefighter.et.tudelft.nl/~arthur/cvsd/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://tiefighter.et.tudelft.nl/~arthur/cvsd/
COMMENT=	Run CVS pserver in a chroot-ed environment

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=	YES
USE_PERL5=	YES
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=	YES

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libwrap

RCD_SCRIPTS=	cvsd

EGDIR=          ${PREFIX}/share/examples/cvsd
CONF_FILES=     ${EGDIR}/cvsd.conf.example ${PKG_SYSCONFDIR}/cvsd.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
