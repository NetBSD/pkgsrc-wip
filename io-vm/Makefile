# $NetBSD: Makefile,v 1.8 2012/09/30 05:44:15 asau Exp $

.include "../../wip/io-base/version.mk"

PKGNAME=		${DISTNAME:S/io-/&vm-/}
CATEGORIES=		lang
LICENSE=		modified-bsd

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		http://www.iolanguage.com/
COMMENT=		Small programming language

SUBST_CLASSES+=			disable-addons
SUBST_STAGE.disable-addons=	pre-configure
SUBST_MESSAGE.disable-addons=	Disabling all addons
SUBST_FILES.disable-addons=	CMakeLists.txt
SUBST_SED.disable-addons=	-e 's,^add_subdirectory(addons),\# &,g'

INSTALLATION_DIRS=		bin include/io lib lib/io lib/io/addons

post-install:
	cd ${WRKSRC}/_build/headers && pax -rwpe . ${DESTDIR}${PREFIX}/include/io/

.include "../../mk/bsd.pkg.mk"
