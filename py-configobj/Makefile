# $NetBSD: Makefile,v 1.2 2009/04/18 14:28:42 jihbed Exp $
#

DISTNAME=	configobj-4.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=configobj/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.voidspace.org.uk/python/configobj.html/
COMMENT=	Simple but powerful config file reader and write

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED= 25 24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

DOCDIR=		${PREFIX}/share/doc/${PKGNAME}
IMAGEDIR=		${PREFIX}/share/doc/${PKGNAME}/images
SMILIESDIR=	${PREFIX}/share/doc/${PKGNAME}/smilies
STYLEDIR=		${PREFIX}/share/doc/${PKGNAME}/stylesheets

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${IMAGEDIR}
	${INSTALL_DATA}  ${WRKSRC}/docs/images/*  ${DESTDIR}${IMAGEDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SMILIESDIR}
	${INSTALL_DATA}  ${WRKSRC}/docs/smilies/*  ${DESTDIR}${SMILIESDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${STYLEDIR}
	${INSTALL_DATA}  ${WRKSRC}/docs/stylesheets/*  ${DESTDIR}${STYLEDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
