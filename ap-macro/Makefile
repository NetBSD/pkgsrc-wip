# $NetBSD: Makefile,v 1.6 2012/09/24 16:56:35 asau Exp $

DISTNAME=	mod_macro-1.1.2
PKGNAME=	${DISTNAME:S/mod_/ap-/}
CATEGORIES=	www
MASTER_SITES=	http://www.cri.ensmp.fr/~coelho/mod_macro/

MAINTAINER=	jdunn@opentrend.net
HOMEPAGE=	http://www.cri.ensmp.fr/~coelho/mod_macro/
COMMENT=	Apache module for using macros in config files

PKG_DESTDIR_SUPPORT=	none

CONFLICTS=	ap2-macro-[0-9]*


APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c

DOCDIR=		${PREFIX}/share/doc/${PKGNAME}

pre-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/mod_macro.html ${DOCDIR}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
