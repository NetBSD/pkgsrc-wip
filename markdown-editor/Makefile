# $NetBSD$

DISTNAME=	Markdown-editor-2.10.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=ManuelAriasCalleja/}
GITHUB_PROJECT=	Markdown-editor
GITHUB_TAG=	v${PKGVERSION_NOREV}
FETCH_USING=	curl

MAINTAINER=	pkgsrc-wip@NetBSD.org
HOMEPAGE=	https://github.com/ManuelAriasCalleja/Markdown-editor
COMMENT=	WYSIWYG Markdown editor with TeX formulas and diagrams (Qt6)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c++
USE_TOOLS+=		pkg-config
CMAKE_PREFIX_PATH+=	${PREFIX}/qt6
CMAKE_CONFIGURE_ARGS+=	-DSPELL_CHECK_STATIC=OFF
ICON_THEMES=		yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing Exec path in md-editor.desktop
SUBST_FILES.prefix=	md-editor.desktop
SUBST_SED.prefix=	-e 's|^Exec=md-editor|Exec=${PREFIX}/bin/md-editor|'

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
post-install:
	${INSTALL_DATA}	${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}/LICENSE

.include "../../devel/cmake/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
