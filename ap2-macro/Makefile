# $NetBSD: Makefile,v 1.9 2014/06/22 19:57:10 thomasklausner Exp $

DISTNAME=	mod_macro-1.1.5
PKGNAME=	${DISTNAME:S/mod_/ap2-/}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.cri.ensmp.fr/~coelho/mod_macro/

MAINTAINER=	jdunn@opentrend.net
HOMEPAGE=	http://www.cri.ensmp.fr/~coelho/mod_macro/
COMMENT=	Apache module for using macros in config files


CONFLICTS=	ap-macro-[0-9]*

NO_CONFIGURE=		yes

APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c
APACHE_MODULE_LA=	${DISTNAME:C|-.*||}.la
APACHE_MODULE=		yes

DOCDIR=		${PREFIX}/share/doc/${PKGNAME}

pre-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/mod_macro.html ${DOCDIR}

do-build:
	cd ${WRKSRC} && ${APXS} -c -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_SRC}

do-install:
	cd ${WRKSRC} && ${APXS} -i -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_LA}

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
