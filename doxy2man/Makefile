# $NetBSD$

DISTNAME=	doxy2man-0.0.0.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=gsauthof/}
GITHUB_PROJECT=	doxy2man
GITHUB_TAG=	5ce113f4d2a3fc6712f8eb8606a6b0899dc6f8d1

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/gsauthof/doxy2man
COMMENT=	Create man pages from doxygen XML output
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

# Our asciidoc has no ".py" suffic.
# Honor PREFIX when searching doxbook-xsl files
SUBST_CLASSES+=		edit-pro
SUBST_STAGE.edit-pro=	pre-configure
SUBST_MESSAGE.edit-pro=	Preparing main.pro file ...
SUBST_FILES.edit-pro=	main.pro
SUBST_SED.edit-pro=	-e 's,asciidoc\.py,asciidoc,g'
SUBST_SED.edit-pro+=	-e 's,/usr/share/asciidoc,${PREFIX}/share/asciidoc,g'

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

post-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
            ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} doxy2man.8

do-install:
	cd ${WRKSRC} &&						\
		${INSTALL_PROGRAM} ${WRKSRC}/doxy2man		\
			${DESTDIR}${PREFIX}/bin ;		\
		${INSTALL_MAN} ${WRKSRC}/doxy2man.8		\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
