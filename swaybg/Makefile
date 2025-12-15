# $NetBSD$

DISTNAME=	swaybg-1.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=swaywm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://swaywm.org/
COMMENT=	Wallpaper tool for Wayland compositors
LICENSE=	mit

USE_TOOLS+=	pkg-config
TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

SUBST_CLASSES+=		nogit
SUBST_STAGE.nogit=	pre-configure
SUBST_MESSAGE.nogit=	Set version
SUBST_FILES.nogit+=	meson.build
SUBST_SED.nogit+=	-e 's/git =/\#git =/g'
SUBST_SED.nogit+=	-e 's/git.found()/false/g'
SUBST_SED.nogit+=	-e '/project_version/s/@0@/${PKGVERSION}/g'

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	scdoc < ${WRKSRC}/swaybg.1.scd > ${WRKSRC}/swaybg.1
	${INSTALL_MAN} ${WRKSRC}/swaybg.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/swaybg.1


.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
