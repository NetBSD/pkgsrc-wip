# $NetBSD: Makefile,v 1.6 2015/01/10 20:15:19 thomasklausner Exp $
#

DISTNAME=	emerald-themes-becbfa5be845a4721d8912ed55c3ff4607fe97ba
PKGNAME=	emerald-themes-0.6.99
CATEGORIES=	wm
MASTER_SITES=	http://cgit.compiz.org/fusion/decorators/emerald-themes/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.compiz.org/EmeraldThemeManager
COMMENT=	Themes for the Emerald window decorator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
USE_TOOLS+=	aclocal autoconf autoheader automake autoreconf bash gmake gtar
GNU_CONFIGURE=	yes

REPLACE_BASH=	themes/import.sh

SUBST_CLASSES+=		gtar
SUBST_SED.gtar=		-e "s|tar|${PREFIX}/bin/gtar|1"
SUBST_MESSAGE.gtar=	Replacing tar.
SUBST_FILES.gtar=	themes/import.sh
SUBST_STAGE.gtar=	post-configure

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
