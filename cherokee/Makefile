# $NetBSD: Makefile,v 1.8 2004/02/17 02:55:17 blef Exp $
#

DISTNAME=	cherokee-0.4.4-pre3
PKGNAME=	${DISTNAME:S/-pre/rc/}
WRKSRC=		${WRKDIR}/cherokee-0.4.4
CATEGORIES=	www
MASTER_SITES=	ftp://alobbs.com/cherokee/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.alobbs.com/cherokee/
COMMENT=	Extremely fast and tiny web server

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin

RCD_SCRIPTS=	cherokee

EGDIR=		${PREFIX}/share/examples/cherokee

CONF_FILES=	${EGDIR}/cherokee.conf.default ${PKG_SYSCONFDIR}/cherokee.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cherokee.conf \
		${EGDIR}/cherokee.conf.default

.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
