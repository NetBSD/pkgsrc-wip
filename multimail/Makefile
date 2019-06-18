# $NetBSD$

DISTNAME=	mmail-0.52
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=multimail/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://multimail.sourceforge.io/
COMMENT=	Offline mail reader for Blue Wave, QWK, OMEN, SOUP and OPX
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
