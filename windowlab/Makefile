# $NetBSD: Makefile,v 1.6 2003/07/05 22:03:18 xtraeme Exp $
#

DISTNAME=	windowlab-1.11
CATEGORIES=	wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.nickgravgaard.com/windowlab/
COMMENT=	Small and simple window manager

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GMAKE=	YES
USE_X11=	YES

PKG_SYSCONFSUBDIR=	windowlab

EGDIR=		${PREFIX}/share/examples/windowlab
CONF_FILES=	${EGDIR}/menurc.default ${PKG_SYSCONFDIR}/menurc

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/menurc.sample ${EGDIR}/menurc.default

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
