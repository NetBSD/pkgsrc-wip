# $NetBSD$

DISTNAME=	mxml-4.0.3
PKGNAME=	${DISTNAME:S/mxml/mxml4/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelrsweet/}
GITHUB_PROJECT=	mxml
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.minixml.org/
COMMENT=	Small XML parsing library
LICENSE=	apache-2.0

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-sanitizer=no

PKGCONFIG_OVERRIDE+=		mxml4.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
