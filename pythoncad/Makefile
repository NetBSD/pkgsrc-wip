# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	PythonCAD-DS1-R37
PKGNAME=	${PYPKGPREFIX}-pythoncad-37
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pythoncad/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://pythoncad.sourceforge.net/dokuwiki/doku.php
COMMENT=	PythonCAD is a CAD package written, surprisingly enough, in Python
LICENSE=	gnu-gpl-v2

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	bin \
			${PREFIX}/share/${PKGBASE} \
			${DOCSDIR}

DEPENDS=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
REPLACE_PYTHON=	${WRKSRC}/gtkpycad.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

SUBST_CLASSES+=			fix-img
SUBST_STAGE.fix-img=		pre-configure
SUBST_MESSAGE.fix-img=		fixing image file location
SUBST_FILES.fix-img=		PythonCAD/Interface/Gtk/gtkimage.py
SUBST_SED.fix-img=		-e 's,gtkpycad.png,${PREFIX}/share/${PKGBASE}/gtkpycad.png,g'

INSTALL_DOCS=	README \
		TODO \
		prefs.py \
		pythoncad.xsd

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gtkpycad.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gtkpycad.png ${DESTDIR}${PREFIX}/share/${PKGBASE}
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
