# $NetBSD: Makefile,v 1.1.1.1 2003/04/25 17:00:18 xtraeme Exp $
#

DISTNAME=	cherokee-0.4.3-pre9
PKGNAME=	${DISTNAME:S/-pre/rc/}
CATEGORIES=	www
MASTER_SITES=	ftp://alobbs.com/cherokee/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://alobbs.com/cherokee/
COMMENT=	Extremely fast and tiny web server

WRKSRC=		${WRKDIR}/cherokee-0.4.3

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

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
