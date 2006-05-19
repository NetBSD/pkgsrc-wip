# $NetBSD: Makefile,v 1.18 2006/05/19 16:51:14 ykomatsu Exp $
#

DISTNAME=	cherokee-0.4.30
CATEGORIES=	www
MASTER_SITES=	http://www.0x50.org/download/0.4/0.4.30/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.0x50.org/
COMMENT=	Extremely fast and tiny web server

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--bindir=${PREFIX:Q}/sbin

RCD_SCRIPTS=	cherokee

EGDIR=		${PREFIX}/share/examples/cherokee

CONF_FILES=	${EGDIR:Q}/cherokee.conf.default ${PKG_SYSCONFDIR:Q}/cherokee.conf

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR:Q}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/cherokee.conf.sample \
		${EGDIR:Q}/cherokee.conf.default

.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
