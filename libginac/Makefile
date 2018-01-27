# $NetBSD: Makefile,v 1.5 2015/02/13 22:07:35 jihbed Exp $

DISTNAME=	ginac-1.6.3
PKGNAME=	lib${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://www.ginac.de/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ginac.de/
COMMENT=	The GiNaC symbolic framework
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_CMAKE=	yes
INFO_FILES=	YES
USE_TOOLS+=	bison flex pkg-config makeinfo
USE_LANGUAGES=	c 	c++

PKGCONFIG_OVERRIDE+=	ginac.pc.in

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,python,python${PYVERSSUFFIX},g'
SUBST_FILES.paths+=	ginsh/CMakeLists.txt
SUBST_MESSAGE.paths=	Fixing header search paths


.include "../../mk/readline.buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.cln+=		cln>=1.1.6
.include "../../math/cln/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
