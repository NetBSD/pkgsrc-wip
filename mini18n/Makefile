# $NetBSD: Makefile,v 1.2 2013/02/17 19:41:06 othyro Exp $
#

DISTNAME=	mini18n-0.2.1
CATEGORIES=	devel
MASTER_SITES=	http://download.tuxfamily.org/yabause/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yabause.org/
COMMENT=	Minimal translation library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

SUBST_CLASSES+=		mandir
SUBST_FILES.mandir=	doc/CMakeLists.txt
SUBST_MESSAGE.mandir=	Fixing PKGMANDIR.
SUBST_SED.mandir=	-e "s|share/man|${PKGMANDIR}|g"
SUBST_STAGE.mandir=	post-patch

.include "../../mk/bsd.pkg.mk"
