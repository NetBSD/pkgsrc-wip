# $NetBSD$

DISTNAME=	nscde-2.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=NsCDE/}
GITHUB_PROJECT=	NsCDE

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/NsCDE/NsCDE
COMMENT=	Not So Common Desktop Environment
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gsed

DEPENDS+=	fvwm3-[0-9]*:../../wm/fvwm3
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	ksh93-[0-9]*:../../shells/ksh93
DEPENDS+=	stalonetray-[0-9]*:../../x11/stalonetray

PYTHON_VERIONS_INCOMPATIBLE+=	27

.include "../../lang/python/application.mk"
CONFIGURE_ARGS+=	--with-python-shebang=${PYTHONBIN}

UNAME_M!=		uname -m
PLIST_SUBST+=		UNAME_M=${UNAME_M}
PLIST_SUBST+=		OPSYS=${OPSYS}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
