# $NetBSD: Makefile,v 1.3 2003/06/22 04:08:39 schnoebe Exp $
# FreeBSD Id: ports/devel/cvsd/Makefile,v 1.18 2003/04/26 22:38:53 nork Exp

DISTNAME=	cvsd-0.9.19
CATEGORIES=	devel
MASTER_SITES=	http://tiefighter.et.tudelft.nl/~arthur/cvsd/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://tiefighter.et.tudelft.nl/~arthur/cvsd/
COMMENT=	run CVS pserver in a chroot-ed environment

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=	YES
USE_PERL5=	YES
USE_GMAKE=	YES
USE_PKGINSTALL=	YES

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libwrap

RCD_SCRIPTS=	cvsd

EGDIR=          ${PREFIX}/share/examples/cvsd
CONF_FILES=     ${EGDIR}/cvsd.conf.example ${PKG_SYSCONFDIR}/cvsd.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
