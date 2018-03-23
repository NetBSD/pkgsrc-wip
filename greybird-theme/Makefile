# $NetBSD$

PKGNAME=	greybird-theme-3.22.7
DISTNAME=	Greybird-${PKGVERSION_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shimmerproject/}

MAINTAINER=	robn@gmx.com
HOMEPAGE=	https://github.com/shimmerproject/Greybird/
COMMENT=	Desktop Suite for Xfce
LICENSE=	cc-by-sa-v3.0 OR gnu-gpl-v2

GITHUB_PROJECT=	Greybird
GITHUB_TAG=	v${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_FILES.makefile=	Makefile.am
SUBST_SED.makefile=	-e "s/SASS = sass/SASS = sass${RUBY_SUFFIX}/"

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-sass-[0-9]*:../../www/ruby-sass
DEPENDS+=	gtk2-engines-murrine-[0-9]*:../../x11/gtk2-engines-murrine

pre-configure:
		cd ${WRKSRC} && ./autogen.sh

.include "../../lang/ruby/rubyversion.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
