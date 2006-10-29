# $NetBSD: Makefile,v 1.8 2006/10/29 08:32:43 shattered Exp $
#

DISTNAME=		glkloader-0.3.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_IFARCHIVE:=programming/glk/implementations/}

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.ifarchive.org/indexes/if-archiveXprogrammingXglkXimplementations.html
COMMENT=		Glk library that loads real glk implementation at runtime

DEPENDS+=		glkterm-[0-9]*:../../wip/glkterm

USE_TOOLS+=		perl

DOCDIR=  ${PREFIX}/share/doc/glkloader
EGDIR=	${DOCDIR}/samples
CONF_FILES=	${EGDIR}/glkloaderrc ${PKG_SYSCONFDIR}/glkloaderrc

post-install:
	${INSTALL_DATA} ${FILESDIR}/glkstart.h ${LOCALBASE}/include/glkloader
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/glkloaderrc ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
