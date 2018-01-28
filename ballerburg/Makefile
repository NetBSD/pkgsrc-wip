# $NetBSD$

DISTNAME=	ballerburg-1.2.0
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/baller/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://baller.tuxfamily.org/
COMMENT=	Classical castle combat game
LICENSE=	gnu-gpl-v3

#USE_TOOLS+=	intltool gmake cmake pkg-config msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++

USE_CMAKE=	yes

LDFLAGS+=	${BUILDLINK_LDADD.gettext}

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
