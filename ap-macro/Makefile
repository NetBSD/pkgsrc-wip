# $NetBSD: Makefile,v 1.3 2004/05/08 18:46:06 blef Exp $

DISTNAME=	mod_macro-1.1.2
PKGNAME=        ${DISTNAME:S/mod_/ap-/}
CATEGORIES=	www
MASTER_SITES=	http://www.cri.ensmp.fr/~coelho/mod_macro/

MAINTAINER=	jdunn@opentrend.net
HOMEPAGE=	http://www.cri.ensmp.fr/~coelho/mod_macro/
COMMENT=        Apache module for using macros in config files

CONFLICTS=      ap2-macro-[0-9]*

USE_BUILDLINK3=         yes

APACHE_MODULE_NAME=     ${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=      ${DISTNAME:C|-.*||}.c

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
